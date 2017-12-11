cpp:main.cpp func.o stock.o median.o common.h stock.h median.h
	g++ -Wall -std=gnu++14 main.cpp func.o stock.o median.o -o $@

func.o:func.cpp common.h
	g++ -c -Wall -std=gnu++14 func.cpp -o $@

stock.o:stock.cpp stock.h
	g++ -c -Wall -std=gnu++14 stock.cpp -o $@

median.o:median.cpp
	g++ -c -Wall -std=gnu++14 $< -o $@

clean:
	rm *.o
	rm cpp
