C=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -std=c++11
LDFLAGS=
LDLIBS= -lm

SRCS=main_szachy.cpp szachy.cpp 
OBJS=$(subst .cpp,.o,$(SRCS)) 


all: szachy_bin 
debug: CPPFLAGS+=-g
debug: LDFLAGS+=-g
debug: szachy_bin

szachy_bin: $(OBJS)
	$(CXX) $(LDFLAGS)  $(OBJS) -o szachy_bin  $(LDLIBS) 



main_szachy.o: main_szachy.cpp szachy.h

szachy.o: szachy.cpp szachy.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) szachy_bin
