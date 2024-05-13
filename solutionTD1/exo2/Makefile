SHELL= bash
TARGET= exo2aTD1 exo2bTD1 exo2cTD1
SRCS=  XWindow.cpp exo2aTD1.cpp exo2bTD1.cpp exo2cTD1.cpp 
CXXFLAGS = -Wall -g
CXX= g++
LDFLAGS= -L/usr/X11R6/lib -lX11

OBJS=$(SRCS:.cpp=.o)
DEPS=$(SRCS:.cpp=.d)

all: $(TARGET)

EXO2A_OBJS= XWindow.o exo2aTD1.o
exo2aTD1: $(EXO2A_OBJS)
	$(CXX) $(CXXFLAGS) $(EXO2A_OBJS) -o $@ $(LDFLAGS) $(LIBS)

EXO2B_OBJS= XWindow.o exo2bTD1.o
exo2bTD1: $(EXO2B_OBJS)
	$(CXX) $(CXXFLAGS) $(EXO2B_OBJS) -o $@ $(LDFLAGS) $(LIBS)

EXO2C_OBJS= XWindow.o exo2cTD1.o
exo2cTD1: $(EXO2C_OBJS)
	$(CXX) $(CXXFLAGS) $(EXO2C_OBJS) -o $@ $(LDFLAGS) $(LIBS)

clean :
	-rm -f $(TARGET) *.o *.d

%.d: %.cpp
	@$(SHELL) -ec '$(CXX) -M $(CXXFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'


-include $(DEPS)





