cpp:main.o speak.o
	g++ main.o speak.o -o cpp

main.o:main.cpp
	g++ -c main.cpp -o main.o

speak.o:speak.cpp
	g++ -c speak.cpp -o speak.o

clean:
	rm *.o
