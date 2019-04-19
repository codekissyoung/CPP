CC=g++

BIN = main

OBJ = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

CPPFLAGS=-std=c++17 -Wall -pedantic -g
# CPPFLAGS=-std=c++17 -Wall -O2

$(BIN) : $(OBJ)
	$(CC) $(CPPFLAGS) $^ -o $@

clean:
	$(RM) *.o
	$(RM) $(BIN)
	$(RM) *.gch
	$(RM) .log.txt
	$(RM) .gdb_history
