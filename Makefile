CC=g++
CPPFLAGS=-Wall -std=gnu++14

cpp:main.cpp func.o stock.o median.o
	$(CC) $(CPPFLAGS) $^ -o $@

func.o:func.cpp common.h
	$(CC) $(CPPFLAGS) -c $^

stock.o:stock.cpp stock.h
	$(CC) $(CPPFLAGS) -c $^

median.o:median.cpp
	$(CC) $(CPPFLAGS) -c $^

clean:
	rm *.o
	rm cpp
