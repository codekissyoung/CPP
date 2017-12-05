cpp:main.cpp func.o common.h
	g++ -Wall -std=gnu++14 main.cpp func.o -o cpp

func.o:func.cpp common.h
	g++ -c -Wall -std=gnu++14 func.cpp -o func.o

clean:
	rm *.o
	rm cpp
