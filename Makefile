PROJECTNAME := snake

LBITS := $(shell getconf LONG_BIT)

ifeq ($(LBITS),64)
# do 64 bit stuff here, like set some CFLAGS
CFLAGS += -m64 -g
else
# do 32 bit stuff here
CFLAGS += -m32 -g
endif

ifndef PKG_CONFIG
PKG_CONFIG=pkg-config
endif

CFLAGS += -pedantic -Wall
LDLIBS += $(shell $(PKG_CONFIG) --libs ncurses)
#INC := -I/

all:    $(PROJECTNAME)

$(PROJECTNAME): $(patsubst %.cpp,%.o,$(wildcard *.cpp))
	g++ $(CFLAGS) -rdynamic  $^ $(LDLIBS) $(LDFLAGS)  -o $@

%.o: %.cpp
	g++ $(CFLAGS) -c $(INC) $<

clean:
	rm -f $(PROJECTNAME) *.o *.d
                
#include $(wildcard *.d)
