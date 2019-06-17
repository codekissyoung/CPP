CC  	 = g++
BIN 	 = main
OBJ 	 = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

CPPFLAGS = -std=c++17 -Wall -pedantic -g -DDEBUG -lcurses -lpthread
#CPPFLAGS = -std=c++17 -O2

$(BIN) : $(OBJ)
	$(CC) $^ -o $@ $(CPPFLAGS)

clean:
	$(RM) *.o
	$(RM) $(BIN)
	$(RM) *.gch
	$(RM) .log.txt
	$(RM) .gdb_history
