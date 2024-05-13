SHELL=bash
TARGET=TD3
SRCS=  XWindow.cpp TD3.cpp Vector4D.cpp Matrix4x4.cpp
#CXXFLAGS = -g -Wall 
CXXFLAGS = -O3 -DNDEBUG
CXX= g++
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





