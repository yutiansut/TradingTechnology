ctppriceview操作手册
written by krenx1983@qq.com
版本1.0 2021/3/5

报价显示

用法：
ctppriceview marketaddr [instrument,instrument ...]
example:
	ctppriceview tcp://180.168.146.187:10110（可用于局域网环境，不指定合约可以订阅所有合约，未测试）
	ctppriceview tcp://180.168.146.187:10110 rb2105,IF2101

支持vi编辑器几乎所有常用移动命令，只列一下其中部分命令。

移动命令：
	上下左右：kjhl（移到下一行的命令有四个：j，+，^N以及回车键），下一版本将支持方向键
	翻页：fbud
	滚动：ye

选择合约：/?
	显示合约搜索小窗口

小窗口命令：
	输入合约号，自动补充匹配的第一项
	上一项：^p
	下一项：^n
	确定：回车键
	删除输入：^h 或者 BackSpace 都可以删除输入字符
	
其它命令：
	刷新界面：^L
	退出：q
	取消正在进行操作：ESC（有命令是需要输入多个字符的，可以取消操作）