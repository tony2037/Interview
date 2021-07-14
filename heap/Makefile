CC=g++
CPPFLAGS=-g

SRC=$(wildcard *.cpp)
OBJS=$(patsubst %.cpp,%.o,$(SRC))


all: test

$(OBJS): %.o:%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $^
test: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	$(RM) *.o test