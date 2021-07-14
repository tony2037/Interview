CC=g++
CPPFLAGS=-g
SRCS=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRCS))

all: main
$(OBJS): %.o:%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $^
main: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	$(RM) *.o main