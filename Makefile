cpp:main.cpp func.o stock.o common.h stock.h
	g++ -Wall -std=gnu++14 main.cpp func.o stock.o -o $@

func.o:func.cpp common.h
	g++ -c -Wall -std=gnu++14 func.cpp -o $@

stock.o:stock.cpp stock.h
	g++ -c -Wall -std=gnu++14 stock.cpp -o $@

clean:
	rm *.o
	rm cpp
