SHELL= bash
TARGET= exo1aTD1 exo1bTD1
SRCS= exo1aTD1.cpp exo1bTD1.cpp
CXXFLAGS = -Wall -g
CXX= g++
LDFLAGS=

OBJS=$(SRCS:.cpp=.o)
DEPS=$(SRCS:.cpp=.d)

all: $(TARGET)

EXO1A_OBJS= exo1aTD1.o
exo1aTD1: $(EXO1A_OBJS)
	$(CXX) $(CXXFLAGS) $(EXO1A_OBJS) -o $@ $(LDFLAGS) $(LIBS)

EXO1B_OBJS= exo1bTD1.o
exo1bTD1: $(EXO1B_OBJS)
	$(CXX) $(CXXFLAGS) $(EXO1B_OBJS) -o $@ $(LDFLAGS) $(LIBS)

clean :
	-rm -f $(TARGET) *.o *.d

%.d: %.cpp
	@$(SHELL) -ec '$(CXX) -M $(CXXFLAGS) $< \
		| sed '\''s/\($*\)\.o[ :]*/\1.o $@ : /g'\'' > $@; \
		[ -s $@ ] || rm -f $@'


-include $(DEPS)





