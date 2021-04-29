.SUFFIXES:  .c .cpp .o .obj .a .lib

CPP=cl
LINK=link
LIB32=lib 
PREP=cl -nologo -EP
PUMP=pump
COPY=copy /y
DEL=del
MAKE=nmake
ECHO=echo

.cpp.obj:
	$(CPP) $(CPPFLAGS) $(INCLUDEDIR) -c $< >> output
	move $(@F) $(@D)

ISLIB=N
DEFINES=-DWINDOWS -DMSVC
target=ctppriceview.exe

DEBUG_DEFINE=

APPEND_CPPFLAGS=-nologo -EHsc -MD -O2 -GF -FD

PROFILE_CPPFLAGS=

WARNING_CPPFLAGS=-W3

CPPFLAGS= -std=c++11    $(APPEND_CPPFLAGS) $(PROFILE_CPPFLAGS) $(WARNING_CPPFLAGS) $(DEBUG_DEFINE) $(DEFINES)

LIBS= kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib    

DEBUG_LDFLAGS=

MAP_LDFLAGS=

PROFILE_LDFLAGS=

WARNING_LDFLAGS=/WARN:2

LDFLAGS=    -nologo /FIXED:NO $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS) $(WARNING_LDFLAGS)

LIBARFLAGS=    -nologo $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)

DLLARFLAGS=    -nologo /dll $(MAP_LDFLAGS) $(DEBUG_LDFLAGS) $(PROFILE_LDFLAGS)


all: code

code: clearoutput $(target)

clearoutput:
	@$(ECHO) Compiling... > output

ctppriceview_obj= .\ctppriceview.obj 
ctppriceview_lib=/libpath:.\ thostmduserapi_se.lib pdcurses.lib
ctppriceview_include=
ctppriceview_includedir=-I.\.

all_objs= $(ctppriceview_obj) 
all_libs= $(ctppriceview_lib) 
INCLUDEDIR= $(ctppriceview_includedir) 

.\ctppriceview.obj: .\ctppriceview.cpp $(ctppriceview_include)  

copytargetall= 
pumptargetall= 

$(target): $(all_objs)
	$(LINK) $(LDFLAGS) -out:$@ $(all_objs) $(all_libs) $(LIBS) >> output


clean:
	-$(DEL) $(ctppriceview_obj)
	-$(DEL) $(copytargetall)
	-$(DEL) $(pumptargetall)
	-$(DEL) $(target)

pump: $(pumptargetall)

