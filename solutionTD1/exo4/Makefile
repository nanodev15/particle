SHELL=bash
TARGET=exo4TD1
SRCS=  XWindow.cpp exo4TD1.cpp 
# CXXFLAGS = -O -DNDEBUG -pg
 CXXFLAGS = -O3
# -DNDEBUG 
#CXXFLAGS = -g -Wall 
CXX=g++
LDFLAGS= -L/usr/X11R6/lib -lX11

OBJS=$(SRCS:.cpp=.o)

DEPS=$(SRCS:.cpp=.d)


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS) $(LIBS)

clean :
	-rm -f $(TARGET) *.o *.d

%.d: %.cpp
	@$(SHELL) -ec '$(CXX) -M $(CXXFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'


-include $(DEPS)





