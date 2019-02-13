CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		knapsack.o

LIBS =

TARGET =	knapsack

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
