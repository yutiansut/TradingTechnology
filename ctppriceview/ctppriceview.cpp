#include <iostream>
#include <float.h>
#include <math.h>
#include "ctppriceview.h"
#ifdef _WIN32
#undef getch
#undef ungetch
#include<conio.h>
#endif
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#ifndef _WIN32
#define strnicmp strncasecmp
#endif

#if !(defined(WIN32) || defined(_WIN32) || defined(WIN64))
#include <unistd.h>
#else
int opterr = 1, optind = 1, optopt, optreset;
char* optarg;
int getopt(int argc, char* argv[], const char* ostr)
{
	static char* place = "";		/* option letter processing */
	const char* oli;				/* option letter list index */

	if (optreset || !*place) {		/* update scanning pointer */
		optreset = 0;
		if (optind >= argc || *(place = argv[optind]) != '-') {
			place = "";
			return (EOF);
		}
		if (place[1] && *++place == '-') {	/* found "--" */
			++optind;
			place = "";
			return (EOF);
		}
	}					/* option letter okay? */
	if ((optopt = (int)*place++) == (int)':' ||
		!(oli = strchr(ostr, optopt))) {
		/*
		 * if the user didn't specify '-' as an option,
		 * assume it means EOF.
		 */
		if (optopt == (int)'-')
			return (EOF);
		if (!*place)
			++optind;
		return ('?');
	}
	if (*++oli != ':') {			/* don't need argument */
		optarg = NULL;
		if (!*place)
			++optind;
	}
	else {					/* need an argument */
		if (*place)			/* no white space */
			optarg = place;
		else if (argc <= ++optind) {	/* no arg */
			place = "";
			if (*ostr == ':')
				return (':');
			return ('?');
		}
		else				/* white space */
			optarg = argv[optind];
		place = "";
		++optind;
	}
	return (optopt);			/* dump back option letter */
}
#endif	/* __THINK_WINDOWS__ */

class semaphore
{
public:
	semaphore(int value = 1) :count(value) {}

	void wait()
	{
		std::unique_lock<std::mutex> lck(mt);
		if (--count < 0)//资源不足挂起线程
			cv.wait(lck);
	}

	void signal()
	{
		std::unique_lock<std::mutex> lck(mt);
		if (++count <= 0)//有线程挂起，唤醒一个
			cv.notify_one();
	}

private:
	int count;
	std::mutex mt;
	std::condition_variable cv;
};

char input_buffer[100] = { 0 };
std::vector<quotation_t> vquotes;
std::map<std::string, size_t> mquotes; // 索引，合约号==>vquotes下标
int ConnectionStatus = CONNECTION_STATUS_DISCONNECTED;
char** instruments = NULL; // 要订阅的合约列表
size_t instrument_count = 0;

std::mutex _lock;
semaphore _sem;
std::vector< std::function<void()> > _vTasks;

typedef struct {
	char name[30];
	int width;
} column_item_t;

column_item_t column_items[]={
#define COL_SYMBOL			0		// 合约
	{"合约",		20},
#define COL_SYMBOL_NAME		1		// 名称
	{"名称",		20},
#define COL_CLOSE			2		// 现价
	{"现价",		10},
#define COL_PERCENT			3		// 涨幅
	{"涨幅",		10},
#define COL_VOLUME			4		// 总手
	{"总手",		10},
#define COL_TRADE_VOLUME	5		// 现手
	{"现手",		10},
#define COL_ADVANCE			6		// 涨跌
	{"涨跌",		10},
#define COL_OPEN			7		// 开盘
	{"开盘",		10},
#define COL_HIGH			8		// 最高
	{"最高",		10},
#define COL_LOW				9		// 最低
	{"最低",		10},
#define COL_BID_PRICE		10		// 买价
	{"买价",		10},
#define COL_BID_VOLUME		11		// 买量
	{"买量",		10},
#define COL_ASK_PRICE		12		// 卖价
	{"卖价",		10},
#define COL_ASK_VOLUME		13		// 卖量
	{"卖量",		10},
#define COL_PREV_SETTLEMENT	14		// 昨结
	{"昨结",		10},
#define COL_SETTLEMENT		15		// 今结
	{"今结",		10},
#define COL_PREV_CLOSE		16		// 昨收
	{"昨收",		10},
#define COL_OPENINT			17		// 今仓
	{"今仓",		10},
#define COL_PREV_OPENINT	18		// 昨仓
	{"昨仓",		10},
#define COL_AVERAGE_PRICE	19		// 均价
	{"均价",		10},
#define COL_HIGH_LIMIT		20		// 涨停
	{"涨停",		10},
#define COL_LOW_LIMIT		21		// 跌停
	{"跌停",		10},
#define COL_TRADINGDAY		22		// 交易日
	{"交易日",		10}
};
std::vector<int> vcolumns;	// columns in order
std::map<int,bool> mcolumns;	// column select status

// Mainboard Curses
int curr_line=0,curr_col=1,max_lines,max_cols=7;
int curr_pos=0,curr_col_pos=2;

// Corner Curses
WINDOW *corner_win=NULL;
int corner_curr_line=0,corner_curr_col=1,corner_max_lines=5,corner_max_cols=20;
int corner_curr_pos=0,corner_curr_col_pos=0;
char corner_input[100],strsearching[30],strmatch[30];

int main(int argc,char *argv[])
{
	if (argc != 2 && argc != 3)
	{
		std::cout << "usage:ctppriceview marketaddr [instrument,instrument ...]" << std::endl;
		std::cout << "example:ctppriceview tcp://180.168.146.187:10100" << std::endl;
		std::cout << "example:ctppriceview tcp://180.168.146.187:10100 rb2105,IF2101" << std::endl;
		return -1;
	}

	char* servaddr = argv[1];
	const char* p;
	
	// instruments
	if (argc == 3) {
		instrument_count =1;
		for (p = argv[2]; *p != '\0'; p++)
			if (*p == ',')
				instrument_count++;
	
		instruments = (char**)malloc(sizeof(char*)* instrument_count);
		char** instrument = instruments;
		char* token=NULL;
		p = argv[2];
		for (int i=0; i<instrument_count; i++) {
			if (token == NULL) {
				token = strtok(argv[2], ",");
			}
			else {
				token = strtok(NULL, ",");
			}
			*instrument++ = token;
		}
	}

	if (strstr(servaddr,"://") == NULL) {
		std::cout << "invalid addr format" << std::endl;
		return -1;
	}
	CThostFtdcMdApi* pMdApi = CThostFtdcMdApi::CreateFtdcMdApi();
	CCTPMdSpiImp Spi(pMdApi);
	pMdApi->RegisterSpi(&Spi);
	pMdApi->RegisterFront(servaddr);
	pMdApi->Init();


	// Init Columns
	mcolumns[COL_SYMBOL]=true;vcolumns.push_back(COL_SYMBOL);
	mcolumns[COL_SYMBOL_NAME]=false;vcolumns.push_back(COL_SYMBOL_NAME);
	mcolumns[COL_CLOSE]=true;vcolumns.push_back(COL_CLOSE);
	mcolumns[COL_PERCENT]=true;vcolumns.push_back(COL_PERCENT);
	mcolumns[COL_VOLUME]=true;vcolumns.push_back(COL_VOLUME);
	mcolumns[COL_TRADE_VOLUME]=true;vcolumns.push_back(COL_TRADE_VOLUME);
	mcolumns[COL_BID_PRICE]=true;vcolumns.push_back(COL_BID_PRICE);
	mcolumns[COL_BID_VOLUME]=true;vcolumns.push_back(COL_BID_VOLUME);
	mcolumns[COL_ASK_PRICE]=true;vcolumns.push_back(COL_ASK_PRICE);
	mcolumns[COL_ASK_VOLUME]=true;vcolumns.push_back(COL_ASK_VOLUME);
	mcolumns[COL_PREV_SETTLEMENT]=true;vcolumns.push_back(COL_PREV_SETTLEMENT);
	mcolumns[COL_ADVANCE]=true;vcolumns.push_back(COL_ADVANCE);
	mcolumns[COL_OPEN]=true;vcolumns.push_back(COL_OPEN);
	mcolumns[COL_HIGH]=true;vcolumns.push_back(COL_HIGH);
	mcolumns[COL_LOW]=true;vcolumns.push_back(COL_LOW);
	mcolumns[COL_HIGH_LIMIT] = true; vcolumns.push_back(COL_HIGH_LIMIT);
	mcolumns[COL_LOW_LIMIT] = true; vcolumns.push_back(COL_LOW_LIMIT);
	mcolumns[COL_AVERAGE_PRICE]=true;vcolumns.push_back(COL_AVERAGE_PRICE);
	mcolumns[COL_PREV_CLOSE]=true;vcolumns.push_back(COL_PREV_CLOSE);
	mcolumns[COL_OPENINT]=true;vcolumns.push_back(COL_OPENINT);
	mcolumns[COL_PREV_OPENINT]=true;vcolumns.push_back(COL_PREV_OPENINT);
	mcolumns[COL_SETTLEMENT]=true;vcolumns.push_back(COL_SETTLEMENT);
	mcolumns[COL_TRADINGDAY] = true; vcolumns.push_back(COL_TRADINGDAY);

	std::thread workthread(&work_thread);
	std::thread timerthread(&time_thread);

	// Idle
	while(1){
		int ch;
#ifdef _WIN32
		ch=getch();
#else
		ch=getchar();
#endif
		post_task(std::bind(on_key_pressed, ch));
		//if(ch=='q'){
		//	break;
		//}
	}

	return 0;
}

void post_task(std::function<void()> task)
{
	_lock.lock();
	_vTasks.push_back(task);
	_lock.unlock();
	_sem.signal();
}

void HandleTickTimeout()
{
	display_status();
	refresh();
	if(corner_win){
		corner_redraw();
		wrefresh(corner_win);
	}
}

int move_forward_1_page()
{
	int i;
	for(i=0;i<max_lines;i++)
		scroll_forward_1_line();
	return 0;
}
int move_backward_1_page()
{
	int i;
	for(i=0;i<max_lines;i++)
		scroll_backward_1_line();

	return 0;
}
int move_forward_half_page()
{
	int i;
	for(i=0;i<max_lines/2;i++)
		scroll_forward_1_line();
	return 0;
}
int move_backward_half_page()
{
	int i;
	for(i=0;i<max_lines/2;i++)
		scroll_backward_1_line();
	return 0;
}
int goto_page_top()
{
	if(vquotes.size()==0)
		return 0;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}else{
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}

	return 0;
}
int goto_page_bottom()
{
	if(vquotes.size()==0)
		return 0;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
	if(curr_line==vquotes.size()-curr_pos)	// Already bottom
		return 0;
	if(vquotes.size()-curr_pos<max_lines){
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=vquotes.size()-curr_pos;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}else{
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=max_lines;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}

	return 0;
}
int goto_page_middle()
{
	if(vquotes.size()==0)
		return 0;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
	if(vquotes.size()-curr_pos==1)	// Only 1 line
		return 0;
	if(vquotes.size()-curr_pos<max_lines){
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=(vquotes.size()-curr_pos)/2+1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}else{
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=max_lines/2+1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}

	return 0;
}

int scroll_forward_1_line()
{
	if(vquotes.size()==0)
		return 0;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
	if(curr_pos==vquotes.size()-1){	//Already bottom
		return 0;
	}
	move(1,0);
	setscrreg(1,max_lines);
	scroll(stdscr);
	setscrreg(0,max_lines+1);
	
	if(curr_line==1){
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}else{
		curr_line--;
	}
	
	curr_pos++;
	if(vquotes.size()-curr_pos>=max_lines){
		display_quotation(vquotes[curr_pos+max_lines-1].product_id);
	}
	display_title();

	return 0;
}
int scroll_backward_1_line()
{
	if(vquotes.size()==0)
		return 0;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
	if(curr_pos==0){	//Already top
		return 0;
	}
	move(1,0);
	setscrreg(1,max_lines);
	scrl(-1);
	setscrreg(0,max_lines+1);
	
	if(curr_line==max_lines){
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}else{
		curr_line++;
	}
	
	curr_pos--;
	display_quotation(vquotes[curr_pos].product_id);
	display_status();

	return 0;
}

int move_forward_1_line()
{
	if(vquotes.size()==0)
		return 0;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
		return 0;
	}
	if(curr_line==vquotes.size()-curr_pos)	// Already bottom
		return 0;
	if(curr_line!=max_lines){
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line++;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}else{
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		move(1,0);
		setscrreg(1,max_lines);
		scroll(stdscr);
		setscrreg(0,max_lines+1);
		curr_pos++;
		display_quotation(vquotes[curr_pos+max_lines-1].product_id);	// new line
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}

	return 0;
}
int scroll_left_1_column()
{
	int i;
	
	if(curr_col_pos==2)
		return 0;
	while(mcolumns[vcolumns[--curr_col_pos]]==false); //	取消所在列的反白显示
	display_title();
	if(vquotes.size()==0)
		return 0;
	for(i=curr_pos;i<vquotes.size() && i<curr_pos+max_lines;i++)
		display_quotation(vquotes[i].product_id);
	
	return 0;
}
int scroll_right_1_column()
{
	int i;
	
	if(curr_col_pos==sizeof(column_items)/sizeof(column_item_t)-1)
		return 0;
	while(mcolumns[vcolumns[++curr_col_pos]]==false); //	取消所在列的反白显示
	display_title();
	if(vquotes.size()==0)
		return 0;
	for(i=curr_pos;i<vquotes.size() && i<curr_pos+max_lines;i++)
		display_quotation(vquotes[i].product_id);

	return 0;
}

int move_backward_1_line()
{
	if(vquotes.size()==0)
		return 0;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
		return 0;
	}
	if(curr_line==1 && curr_pos==0)	// Already top
		return 0;
	if(curr_line>1){
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line--;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}else{
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		move(1,0);
		setscrreg(1,max_lines);
		scrl(-1);
		setscrreg(0,max_lines+1);
		curr_pos--;
		display_quotation(vquotes[curr_pos].product_id);
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}

	return 0;
}
int goto_file_top()
{
	if(vquotes.size()==0)
		return 0;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
	if(curr_line==1 && curr_pos==0)	// Already top
		return 0;
	if(curr_pos==0){
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}else{
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		int n;
		n=vquotes.size()<max_lines?vquotes.size():max_lines;
		curr_pos=0;
		curr_line=1;
		for(int i=0;i<n;i++){
			display_quotation(vquotes[curr_pos+i].product_id);
		}
// 		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
	
	return 0;
}
int goto_file_bottom()
{
	if(vquotes.size()==0)
		return 0;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
	if(curr_line==vquotes.size()-curr_pos)	// Already bottom
		return 0;
	if(vquotes.size()-curr_pos<=max_lines){
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=vquotes.size()-curr_pos;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}else{
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_pos=vquotes.size()-max_lines;
		curr_line=max_lines;
		for(int i=0;i<max_lines;i++){
			display_quotation(vquotes[curr_pos+i].product_id);
		}
// 		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
	return 0;
}

void focus_quotation(int index)
{
	if(vquotes.size()==0)
		return;
	if(curr_line==0){	// first select
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
	if(index>curr_pos+max_lines-1){
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=max_lines;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
		int i,n;
		
		n=index-(curr_pos+max_lines-1);
		for(i=0;i<n;i++)
			move_forward_1_line();
	}else if(index<curr_pos){
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
		int i,n;
		
		n=curr_pos-index;
		for(i=0;i<n;i++)
			move_backward_1_line();
	}else{
		mvchgat(curr_line,0,-1,A_NORMAL,0,NULL);
		curr_line=index-curr_pos+1;
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	}
}

void display_quotation(const char *product_id)
{
	int i,y,x,pos,maxy,maxx;
	std::vector<int>::iterator iter;

	getmaxyx(stdscr,maxy,maxx);
	i = mquotes[product_id];
	//for(i=0;i<vquotes.size();i++)
	//	if(strcmp(vquotes[i].product_id,product_id)==0)
	//		break;
	if(i<curr_pos || i>curr_pos+max_lines-1)
		return;
	y=i-curr_pos+1;
	x=0;

	move(y,0);
	clrtoeol();

	for(iter=vcolumns.begin(),pos=0;iter!=vcolumns.end();iter++,pos++){
		if(mcolumns[*iter]==false)
			continue;
		if(*iter!=COL_SYMBOL && *iter!=COL_SYMBOL_NAME && pos<curr_col_pos)
			continue;
		if(maxx-x<column_items[*iter].width)
			break;
		switch(*iter){
		case COL_SYMBOL:		//product_id
			mvprintw(y,x,"%-*s",column_items[COL_SYMBOL].width,vquotes[i].product_id);
			x+=column_items[COL_SYMBOL].width;
			break;
		case COL_SYMBOL_NAME:		//product_name
			mvprintw(y,x,"%-*s",column_items[COL_SYMBOL].width,vquotes[i].product_name);
			x+=column_items[COL_SYMBOL_NAME].width+1;
			break;
		case COL_CLOSE:		//close
			if(vquotes[i].price==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_CLOSE].width,'-');
			else
			mvprintw(y,x,"%*.*f",column_items[COL_CLOSE].width,vquotes[i].precision,vquotes[i].price);
			x+=column_items[COL_CLOSE].width+1;
			break;
		case COL_PERCENT:		//close
			if(vquotes[i].prev_settle==DBL_MAX || vquotes[i].prev_settle==0 || vquotes[i].price==DBL_MAX || vquotes[i].price==0)
				mvprintw(y,x,"%*c",column_items[COL_PERCENT].width,'-');
			else if(vquotes[i].price>vquotes[i].prev_settle)
				mvprintw(y,x,"%*.1f%%",column_items[COL_PERCENT].width-1,(vquotes[i].price-vquotes[i].prev_settle)/vquotes[i].prev_settle*100.0);
			else
				mvprintw(y,x,"%*.1f%%",column_items[COL_PERCENT].width-1,(vquotes[i].price-vquotes[i].prev_settle)/vquotes[i].prev_settle*100.0);
			x+=column_items[COL_PERCENT].width+1;
			break;
		case COL_ADVANCE:		//close
			if(vquotes[i].prev_settle==DBL_MAX || vquotes[i].prev_settle==0 || vquotes[i].price==DBL_MAX || vquotes[i].price==0)
				mvprintw(y,x,"%*c",column_items[COL_ADVANCE].width,'-');
			else if(vquotes[i].price>vquotes[i].prev_settle)
				mvprintw(y,x,"%*.*f",column_items[COL_ADVANCE].width-1,vquotes[i].precision,vquotes[i].price-vquotes[i].prev_settle);
			else
				mvprintw(y,x,"%*.*f",column_items[COL_ADVANCE].width-1,vquotes[i].precision,vquotes[i].price-vquotes[i].prev_settle);
			x+=column_items[COL_ADVANCE].width+1;
			break;
		case COL_VOLUME:		//volume
			mvprintw(y,x,"%*d",column_items[COL_VOLUME].width,vquotes[i].quantity);
			x+=column_items[COL_VOLUME].width+1;
			break;
		case COL_BID_PRICE:		//close
			if(vquotes[i].buy_price==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_BID_PRICE].width,'-');
			else
				mvprintw(y,x,"%*.*f",column_items[COL_BID_PRICE].width,vquotes[i].precision,vquotes[i].buy_price);
			x+=column_items[COL_BID_PRICE].width+1;
			break;
		case COL_BID_VOLUME:		//volume
			mvprintw(y,x,"%*d",column_items[COL_BID_VOLUME].width,vquotes[i].buy_quantity);
			x+=column_items[COL_BID_VOLUME].width+1;
			break;
		case COL_ASK_PRICE:		//close
			if(vquotes[i].sell_price==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_ASK_PRICE].width,'-');
			else
				mvprintw(y,x,"%*.*f",column_items[COL_ASK_PRICE].width,vquotes[i].precision,vquotes[i].sell_price);
			x+=column_items[COL_ASK_PRICE].width+1;
			break;
		case COL_ASK_VOLUME:		//volume
			mvprintw(y,x,"%*d",column_items[COL_ASK_VOLUME].width,vquotes[i].sell_quantity);
			x+=column_items[COL_ASK_VOLUME].width+1;
			break;
		case COL_OPEN:		//close
			if(vquotes[i].open_price==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_OPEN].width,'-');
			else
				mvprintw(y,x,"%*.*f",column_items[COL_OPEN].width,vquotes[i].precision,vquotes[i].open_price);
			x+=column_items[COL_OPEN].width+1;
			break;
		case COL_PREV_SETTLEMENT:		//close
			if(vquotes[i].prev_settle==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_PREV_SETTLEMENT].width,'-');
			else
				mvprintw(y,x,"%*.*f",column_items[COL_PREV_SETTLEMENT].width,vquotes[i].precision,vquotes[i].prev_settle);
			x+=column_items[COL_PREV_SETTLEMENT].width+1;
			break;
		case COL_TRADE_VOLUME:		//volume
			mvprintw(y,x,"%*d",column_items[COL_TRADE_VOLUME].width,vquotes[i].trade_volume);
			x+=column_items[COL_TRADE_VOLUME].width+1;
			break;
		case COL_AVERAGE_PRICE:		//close
			if(vquotes[i].average_price==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_AVERAGE_PRICE].width,'-');
			else
				mvprintw(y,x,"%*.*f",column_items[COL_AVERAGE_PRICE].width,vquotes[i].precision,vquotes[i].average_price);
			x+=column_items[COL_AVERAGE_PRICE].width+1;
			break;
		case COL_HIGH:		//close
			if(vquotes[i].high==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_HIGH].width,'-');
			else
				mvprintw(y,x,"%*.*f",column_items[COL_HIGH].width,vquotes[i].precision,vquotes[i].high);
			x+=column_items[COL_HIGH].width+1;
			break;
		case COL_LOW:		//close
			if(vquotes[i].low==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_LOW].width,'-');
			else
				mvprintw(y,x,"%*.*f",column_items[COL_LOW].width,vquotes[i].precision,vquotes[i].low);
			x+=column_items[COL_LOW].width+1;
			break;
		case COL_HIGH_LIMIT:		//close
			if (vquotes[i].high_limit == DBL_MAX)
				mvprintw(y, x, "%*c", column_items[COL_HIGH].width, '-');
			else
				mvprintw(y, x, "%*.*f", column_items[COL_HIGH].width, vquotes[i].precision, vquotes[i].high_limit);
			x += column_items[COL_HIGH].width + 1;
			break;
		case COL_LOW_LIMIT:		//close
			if (vquotes[i].low_limit == DBL_MAX)
				mvprintw(y, x, "%*c", column_items[COL_HIGH].width, '-');
			else
				mvprintw(y, x, "%*.*f", column_items[COL_HIGH].width, vquotes[i].precision, vquotes[i].low_limit);
			x += column_items[COL_HIGH].width + 1;
			break;
		case COL_SETTLEMENT:		//close
			if(vquotes[i].settle==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_SETTLEMENT].width,'-');
			else
				mvprintw(y,x,"%*.*f",column_items[COL_SETTLEMENT].width,vquotes[i].precision,vquotes[i].settle);
			x+=column_items[COL_SETTLEMENT].width+1;
			break;
		case COL_PREV_CLOSE:		//close
			if(vquotes[i].prev_close==DBL_MAX)
				mvprintw(y,x,"%*c",column_items[COL_PREV_CLOSE].width,'-');
			else
				mvprintw(y,x,"%*.*f",column_items[COL_PREV_CLOSE].width,vquotes[i].precision,vquotes[i].prev_close);
			x+=column_items[COL_PREV_CLOSE].width+1;
			break;
		case COL_OPENINT:		//volume
			mvprintw(y,x,"%*d",column_items[COL_OPENINT].width,vquotes[i].openint);
			x+=column_items[COL_OPENINT].width+1;
			break;
		case COL_PREV_OPENINT:		//volume
			mvprintw(y,x,"%*d",column_items[COL_PREV_OPENINT].width,vquotes[i].prev_openint);
			x+=column_items[COL_PREV_OPENINT].width+1;
			break;
		case COL_TRADINGDAY:		//volume
			mvprintw(y, x, "%-*s", column_items[COL_TRADINGDAY].width, vquotes[i].tradingday);
			x += column_items[COL_TRADINGDAY].width + 1;
			break;
		default:
			break;
		}
	}

	if(curr_line!=0)
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
	if(corner_win){
		corner_redraw();
	}
}

void display_status()
{
	int y,x;
	char status[100]={0};
	char tradetime[20]={0};

	struct tm *t;
	time_t tt;
	getmaxyx(stdscr,y,x);
	tt=time(NULL);
	t=localtime(&tt);
	sprintf(tradetime,"%02d:%02d:%02d",t->tm_hour,t->tm_min,t->tm_sec);
	switch (ConnectionStatus)
	{
	case CONNECTION_STATUS_DISCONNECTED:
		strcpy(status,"断线");
		break;
	case CONNECTION_STATUS_CONNECTED:
		strcpy(status,"断线");
		break;
	case CONNECTION_STATUS_LOGINOK:
		strcpy(status,"在线");
		break;
	case CONNECTION_STATUS_LOGINFAILED:
		strcpy(status,"断线");
		break;
	default:
		strcpy(status,"");
		break;
	}
	move(y-1,0);
	clrtoeol();
	
	mvprintw(y-1,0,"[%d/%d]",curr_pos+curr_line,vquotes.size());
	mvprintw(y-1,x-35,"krenx1983@qq.com  %s  %s", status,tradetime);
}

void init_screen()
{
	int i,y,x;

	initscr();
	cbreak();
	nodelay(stdscr,TRUE);
	keypad(stdscr,TRUE);
	noecho();
	curs_set(0);
	scrollok(stdscr,TRUE);
	clear();
	getmaxyx(stdscr,y,x);
	max_lines=y-2;
	display_title();
	for(i=0;i<vquotes.size();i++)
		display_quotation(vquotes[i].product_id);
	display_status();
	if(curr_line!=0)
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
}

void refresh_screen()
{
	int i,y,x;

	endwin();
	initscr();
	cbreak();
	nodelay(stdscr,TRUE);
	keypad(stdscr,TRUE);
	noecho();
	curs_set(0);
	scrollok(stdscr,TRUE);
	clear();
	getmaxyx(stdscr,y,x);
	max_lines=y-2;
	display_title();
	for(i=0;i<vquotes.size();i++)
		display_quotation(vquotes[i].product_id);
	display_status();
	if(curr_line!=0)
		mvchgat(curr_line,0,-1,A_REVERSE,0,NULL);
}


void display_title()
{
	int y,x,pos,maxy,maxx;
	std::vector<int>::iterator iter;

	getmaxyx(stdscr,maxy,maxx);
	y=0;
	x=0;
	move(0,0);
	clrtoeol();
	for(iter=vcolumns.begin(),pos=0;iter!=vcolumns.end();iter++,pos++){
		if(mcolumns[*iter]==false)
			continue;
		if(*iter!=COL_SYMBOL && *iter!=COL_SYMBOL_NAME && pos<curr_col_pos)
			continue;
		if(maxx-x<column_items[*iter].width)
			break;
		switch(*iter){
		case COL_SYMBOL:		//product_id
			mvprintw(y,x,"%-*s",column_items[COL_SYMBOL].width,column_items[COL_SYMBOL].name);
			x+=column_items[COL_SYMBOL].width;
			break;
		case COL_SYMBOL_NAME:		//product_name
			mvprintw(y,x,"%-*s",column_items[COL_SYMBOL_NAME].width,column_items[COL_SYMBOL_NAME].name);
			x+=column_items[COL_SYMBOL_NAME].width+1;
			break;
		case COL_CLOSE:		//close
			mvprintw(y,x,"%*s",column_items[COL_CLOSE].width,column_items[COL_CLOSE].name);
			x+=column_items[COL_CLOSE].width+1;
			break;
		case COL_PERCENT:		//close
			mvprintw(y,x,"%*s",column_items[COL_PERCENT].width,column_items[COL_PERCENT].name);
			x+=column_items[COL_PERCENT].width+1;
			break;
		case COL_ADVANCE:		//close
			mvprintw(y,x,"%*s",column_items[COL_ADVANCE].width,column_items[COL_ADVANCE].name);
			x+=column_items[COL_ADVANCE].width+1;
			break;
		case COL_VOLUME:		//volume
			mvprintw(y,x,"%*s",column_items[COL_VOLUME].width,column_items[COL_VOLUME].name);
			x+=column_items[COL_VOLUME].width+1;
			break;
		case COL_BID_PRICE:		//close
			mvprintw(y,x,"%*s",column_items[COL_BID_PRICE].width,column_items[COL_BID_PRICE].name);
			x+=column_items[COL_BID_PRICE].width+1;
			break;
		case COL_BID_VOLUME:		//volume
			mvprintw(y,x,"%*s",column_items[COL_BID_VOLUME].width,column_items[COL_BID_VOLUME].name);
			x+=column_items[COL_BID_VOLUME].width+1;
			break;
		case COL_ASK_PRICE:		//close
			mvprintw(y,x,"%*s",column_items[COL_ASK_PRICE].width,column_items[COL_ASK_PRICE].name);
			x+=column_items[COL_ASK_PRICE].width+1;
			break;
		case COL_ASK_VOLUME:		//volume
			mvprintw(y,x,"%*s",column_items[COL_ASK_VOLUME].width,column_items[COL_ASK_VOLUME].name);
			x+=column_items[COL_ASK_VOLUME].width+1;
			break;
		case COL_OPEN:		//close
			mvprintw(y,x,"%*s",column_items[COL_OPEN].width,column_items[COL_OPEN].name);
			x+=column_items[COL_OPEN].width+1;
			break;
		case COL_PREV_SETTLEMENT:		//close
			mvprintw(y,x,"%*s",column_items[COL_PREV_SETTLEMENT].width,column_items[COL_PREV_SETTLEMENT].name);
			x+=column_items[COL_PREV_SETTLEMENT].width+1;
			break;
		case COL_TRADE_VOLUME:		//volume
			mvprintw(y,x,"%*s",column_items[COL_TRADE_VOLUME].width,column_items[COL_TRADE_VOLUME].name);
			x+=column_items[COL_TRADE_VOLUME].width+1;
			break;
		case COL_AVERAGE_PRICE:		//close
			mvprintw(y,x,"%*s",column_items[COL_AVERAGE_PRICE].width,column_items[COL_AVERAGE_PRICE].name);
			x+=column_items[COL_AVERAGE_PRICE].width+1;
			break;
		case COL_HIGH:		//close
			mvprintw(y,x,"%*s",column_items[COL_HIGH].width,column_items[COL_HIGH].name);
			x+=column_items[COL_HIGH].width+1;
			break;
		case COL_LOW:		//close
			mvprintw(y,x,"%*s",column_items[COL_LOW].width,column_items[COL_LOW].name);
			x+=column_items[COL_LOW].width+1;
			break;
		case COL_HIGH_LIMIT:		//close
			mvprintw(y, x, "%*s", column_items[COL_HIGH_LIMIT].width, column_items[COL_HIGH_LIMIT].name);
			x += column_items[COL_HIGH_LIMIT].width + 1;
			break;
		case COL_LOW_LIMIT:		//close
			mvprintw(y, x, "%*s", column_items[COL_LOW_LIMIT].width, column_items[COL_LOW_LIMIT].name);
			x += column_items[COL_LOW_LIMIT].width + 1;
			break;
		case COL_SETTLEMENT:		//close
			mvprintw(y,x,"%*s",column_items[COL_SETTLEMENT].width,column_items[COL_SETTLEMENT].name);
			x+=column_items[COL_SETTLEMENT].width+1;
			break;
		case COL_PREV_CLOSE:		//close
			mvprintw(y,x,"%*s",column_items[COL_PREV_CLOSE].width,column_items[COL_PREV_CLOSE].name);
			x+=column_items[COL_PREV_CLOSE].width+1;
			break;
		case COL_OPENINT:		//volume
			mvprintw(y,x,"%*s",column_items[COL_OPENINT].width,column_items[COL_OPENINT].name);
			x+=column_items[COL_OPENINT].width+1;
			break;
		case COL_PREV_OPENINT:		//volume
			mvprintw(y,x,"%*s",column_items[COL_PREV_OPENINT].width,column_items[COL_PREV_OPENINT].name);
			x+=column_items[COL_PREV_OPENINT].width+1;
			break;
		case COL_TRADINGDAY:		//volume
			mvprintw(y, x, "%-*s", column_items[COL_TRADINGDAY].width, column_items[COL_TRADINGDAY].name);
			x += column_items[COL_TRADINGDAY].width + 1;
			break;
		default:
			break;
		}
	}
}

void work_thread()
{
	// Init screen
	init_screen();
	
	// Run
	while (true) {
		_sem.wait();
		_lock.lock();
		auto task = _vTasks.begin();
		if (task == _vTasks.end()) {
			_lock.unlock();
			continue;
		}
		(*task)();
		_vTasks.erase(task);
		_lock.unlock();
	}

	// End screen
	endwin();
}

void time_thread()
{
	while (true) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		post_task(std::bind(HandleTickTimeout));
	}
}

int on_key_pressed(int ch)
{
	int r=0;
	r=on_key_pressed_mainboard(ch);

	refresh();
	if(corner_win){
		corner_redraw();
		wrefresh(corner_win);
	}

	if(r<0){
		endwin();
		exit(0);
	}
	
	return 0;
}
int input_parse(int *num,int *cmd)
{
	const char* p;
	char strnum[10];
	int i;
	int len;

	memset(strnum,0x00,sizeof(strnum));
	for(p=input_buffer,i=0;isdigit(*p);++p,i++)
		strnum[i]=*p;
	*num=atol(strnum);
	switch(*p){
	case '\0':	// uncompleted
		return -1;
	case 'g':
		++p;
		switch(*p){
		case '\0':
			return -1;	// uncompleted
		case 'g':
			*cmd='g';
			break;
		case 'w':
			*cmd=input_buffer[0];
			break;
		default:
			++p;
			len=strlen(p);
			memmove(input_buffer,p,len);
			input_buffer[len]='\0';
			return -1;
		}
		break;
	case '\'':
		++p;
		switch(*p){
		case '\0':
			return -1;	// uncompleted
		case '\'':
			*cmd='\'';
			break;
		default:
			++p;
			len=strlen(p);
			memmove(input_buffer,p,len);
			input_buffer[len]='\0';
			return -1;
		}
		break;
	default:
		*cmd=*p;
		break;
	}
	++p;
	len=strlen(p);
	memmove(input_buffer,p,len);
	input_buffer[len]='\0';

	return 0;
}

int on_key_pressed_mainboard(int ch)
{
	int Num,Cmd;

	if(corner_win){
		on_key_pressed_corner(ch);
		return 0;
	}
	input_buffer[strlen(input_buffer)+1]='\0';
	input_buffer[strlen(input_buffer)]=ch;
	
	if(input_parse(&Num,&Cmd)<0)
		return 0;

	if(Cmd=='q'){
		return -1;
	}
	if(Num==0)
		Num=1;
	switch(Cmd){
	case 27:	// ESC
		break;
	case 12:		// ^L
		refresh_screen();
		break;
	case 'j':
	case 14:		// ^N
	case KEY_DOWN:
	case 13:	// Enter
	case '+':
		for(;Num>0;Num--)
			move_forward_1_line();
		break;
	case 'k':
	case 16:		// ^P
	case KEY_UP:
	case 8: // Backspace
	case '-':
		for(;Num>0;Num--)
			move_backward_1_line();
		break;
	case 'f':	// forward 1 page
	case 6:		// ^F
	case KEY_NPAGE:
		for(;Num>0;Num--)
			move_forward_1_page();
		break;
	case 's':	// sort Asc by selected column
		break;
	case 'S':	// sort Desc by selected column
		break;
	case 'b':
	case 2:		// ^B
	case KEY_PPAGE:
		for(;Num>0;Num--)
			move_backward_1_page();
		break;
	case 'u':	// backward harf page
	case 21:		// ^U
		for(;Num>0;Num--)
			move_backward_half_page();
		break;
	case 'd':	// forward harf page
	case 4:		// ^D
		for(;Num>0;Num--)
			move_forward_half_page();
		break;
	case 'e':	// forward 1 line
	case 5:		// ^E
		for(;Num>0;Num--)
			scroll_forward_1_line();
		break;
	case 'y':	// backward 1 line
	case 25:		// ^Y
		for(;Num>0;Num--)
			scroll_backward_1_line();
		break;
	case 'G':	// bottom line
	case KEY_END:
		goto_file_bottom();
		break;
	case 'g':	// top line
	case KEY_HOME:
		goto_file_top();
		break;
	case 'H':	// screen top
		goto_page_top();
		break;
	case 'L':	// screen bottom
		goto_page_bottom();
		break;
	case 'M':	// screen middle
		goto_page_middle();
		break;
	case '[':	// scroll to left
	case 'h':
	case KEY_LEFT:
		for(;Num>0;Num--)
			scroll_left_1_column();
		break;
	case ']':	// scroll to right
	case 'l':
	case KEY_RIGHT:
		for(;Num>0;Num--)
			scroll_right_1_column();
		break;
	case '^':	// scroll to begin
		break;
	case '$':	// scroll to end
		break;
	case '/':
	case '?':
		corner_reset();
		corner_refresh_screen();
		break;
	default:
		break;
	}
	display_status();

	return 0;
}

void corner_refresh_screen()
{	
	int y,x;

	if(corner_win)
		delwin(corner_win);

	getmaxyx(stdscr,y,x);
	corner_win=newwin(corner_max_lines+3,corner_max_cols+2,y-(corner_max_lines+3)-1,x-(corner_max_cols+2));
	box(corner_win,'|','-');
	mvwaddch(corner_win,0,0,'+');
	mvwaddch(corner_win,0,corner_max_cols+1,'+');
	mvwaddch(corner_win,corner_max_lines+2,0,'+');
	mvwaddch(corner_win,corner_max_lines+2,corner_max_cols+1,'+');
// 	nodelay(stdscr,TRUE);
// 	keypad(stdscr,TRUE);
// 	noecho();
// 	curs_set(0);
// 	scrollok(stdscr,TRUE);
// 	clear();
	corner_redraw();
}

void corner_redraw()
{
	int y,x;

	werase(corner_win);
	getmaxyx(stdscr,y,x);
	corner_win=newwin(corner_max_lines+3,corner_max_cols+2,y-(corner_max_lines+3)-1,x-(corner_max_cols+2));
	box(corner_win,'|','-');
	mvwaddch(corner_win,0,0,'+');
	mvwaddch(corner_win,0,corner_max_cols+1,'+');
	mvwaddch(corner_win,corner_max_lines+2,0,'+');
	mvwaddch(corner_win,corner_max_lines+2,corner_max_cols+1,'+');
	corner_display_input();
	corner_display_matches();
	corner_display_focus();
}

void corner_display_input()
{
	int y,x;

	getmaxyx(stdscr,y,x);
	mvwprintw(corner_win,1,1,strsearching);
}

void corner_display_matches()
{
	int i,j;
	int y,x;
	
	getmaxyx(stdscr,y,x);

// 	if(strlen(strsearching)==0)
// 		return;
	for(i=corner_curr_pos,j=0;i<vquotes.size() && j<5;i++){
		if(strnicmp(vquotes[i].product_id,strsearching,strlen(strsearching))==0){
			if(j==0 && strlen(strsearching)>0){
				mvwprintw(corner_win,j+1,strlen(strsearching)+1,"%s",vquotes[i].product_id+strlen(strsearching));
				mvwchgat(corner_win,j+1,strlen(strsearching)+1,strlen(vquotes[i].product_id)-strlen(strsearching),A_REVERSE,0,NULL);
				strcpy(strmatch,vquotes[i].product_id);
			}
			mvwprintw(corner_win,j+2,1,"%s",vquotes[i].product_id);
			j++;
		}
	}
}

void corner_destroy()
{
	delwin(corner_win);
	corner_win=NULL;
}

void corner_choose_item()
{
	if(corner_curr_line>0){// selected
		int i,j;
		
		for(i=corner_curr_pos,j=0;i<vquotes.size();i++){
			if(strncmp(vquotes[i].product_id,strsearching,strlen(strsearching))==0){
				j++;
				if(j==corner_curr_line){	// found
					corner_destroy();
					refresh_screen();
					focus_quotation(i);
					break;
				}

			}
		}
	}else{// unselected
		int i;
		
		for(i=0;i<vquotes.size();i++){
			if(strcmp(vquotes[i].product_id,strmatch)==0){	// found
				corner_destroy();
				refresh_screen();
				focus_quotation(i);
				return;
			}
		}

		// not found
		corner_destroy();
		refresh_screen();
	}
}
int on_key_pressed_corner(int ch)
{
	int Num,Cmd;
	
	corner_input[strlen(corner_input)+1]=0;
	corner_input[strlen(corner_input)]=ch;
	if(input_parse_corner(&Num,&Cmd)<0)
		return 0;
	
	if(Num==0)
		Num=1;
	switch(Cmd){
	case 27:	// ESC
		corner_destroy();
		refresh_screen();
		return 0;
	case 13:	// Enter
		corner_choose_item();
		return 0;
	case 8:
		corner_delete_char_before_current_pos();
		break;
	case 12:		// ^L
		refresh_screen();
		corner_refresh_screen();
		break;
	case 14:		// ^N
	case KEY_DOWN:
		corner_move_forward_1_line();
		break;
	case 16:		// ^P
	case KEY_UP:
		corner_move_backward_1_line();
		break;
	case KEY_LEFT:
	case 2:		// ^B
		corner_move_left_1_pos();
		break;
	case KEY_RIGHT:
	case 6:		// ^F
		corner_move_right_1_pos();
		break;
	case 4:		// ^D
		corner_delete_char_at_current_pos();
		break;
	case 0:
		corner_research();
		break;
	default:
		break;
	}
	return 0;
}

void corner_research()
{
	corner_curr_line=0,corner_curr_col=1,corner_max_lines=5,corner_max_cols=20;
	corner_curr_pos=0,corner_curr_col_pos=0;
	corner_redraw();
}
void corner_move_left_1_pos()
{
	if(corner_curr_col!=1){
		corner_curr_col--;
	}
	corner_redraw();
}

void corner_move_right_1_pos()
{
	if(corner_curr_col!=corner_max_cols){
		corner_curr_col++;
	}
	corner_redraw();
}

void corner_delete_char_at_current_pos()
{

}

void corner_delete_char_before_current_pos()
{
	if(strlen(strsearching)>0)
		strsearching[strlen(strsearching)-1]='\0';
	corner_research();
}

int input_parse_corner(int *num,int *cmd)
{
	char* p=corner_input;

	*num=0;
	if(isprint(*p)){
		if(strlen(strsearching)==corner_max_cols){
			*p='\0';
			return -1;
		}
		strsearching[strlen(strsearching)+1]='\0';
		strsearching[strlen(strsearching)]=*p;
		*cmd=0;
	}else{
		*cmd=*p;
	}
	*p='\0';
	
	return 0;
}

void corner_move_forward_1_line()
{
	if(corner_curr_line==0){	// first select
		int i;
		
		for(i=corner_curr_pos;i<vquotes.size();i++){
			if(strncmp(vquotes[i].product_id,strsearching,strlen(strsearching))==0)
				break;
		}
		if(i==vquotes.size())
			return;
		corner_curr_line=1;
		corner_curr_pos=i;
		corner_redraw();
		return;
	}

	int i,j;
	
	for(i=corner_curr_pos,j=0;i<vquotes.size() && j<=corner_curr_line;i++){
		if(strncmp(vquotes[i].product_id,strsearching,strlen(strsearching))==0)
			j++;
	}
	if(j<=corner_curr_line)	// Already bottom
		return;

	if(corner_curr_line!=corner_max_lines){
		corner_curr_line++;
	}else{
		int i,j,next_pos;
		
		for(i=corner_curr_pos,j=0;i<vquotes.size();i++){
			if(strncmp(vquotes[i].product_id,strsearching,strlen(strsearching))==0){
				j++;
				if(j==2)
					next_pos=i;
				if(j>corner_curr_line)
					break;
			}
		}
		if(j<corner_curr_line)	// Already bottom
			return;
		corner_curr_pos=next_pos;
	}
	corner_redraw();
}

void corner_move_backward_1_line()
{
	if(corner_curr_line==0){	// first select
		int i;
		
		for(i=corner_curr_pos;i<vquotes.size();i++){
			if(strncmp(vquotes[i].product_id,strsearching,strlen(strsearching))==0)
				break;
		}
		if(i==vquotes.size())
			return;
		corner_curr_line=1;
		corner_curr_pos=i;
		corner_redraw();
		return;
	}
	
	if(corner_curr_line==1){
		int i;
		
		for(i=corner_curr_pos-1;i>=0;i--){
			if(strncmp(vquotes[i].product_id,strsearching,strlen(strsearching))==0)
				break;
		}
		if(i<0)	// Already top
			return;
		corner_curr_pos=i;
	}else{
		corner_curr_line--;
	}

	corner_redraw();
}

void corner_reset()
{
	corner_curr_line=0,corner_curr_col=1,corner_max_lines=5,corner_max_cols=20;
	corner_curr_pos=0,corner_curr_col_pos=0;
	memset(corner_input,0x00,sizeof(corner_input));
	memset(strsearching,0x00,sizeof(strsearching));
	memset(strmatch,0x00,sizeof(strmatch));
}

void corner_display_focus()
{
	if(corner_curr_line!=0)
		mvwchgat(corner_win,corner_curr_line+1,1,corner_max_cols,A_REVERSE,0,NULL);
}
