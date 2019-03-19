CC=g++

BIN = main

OBJ = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

CPPFLAGS=-Wall -std=gnu++14 -g

$(BIN) : $(OBJ)
	$(CC) $(CPPFLAGS) $^ -o $@

clean:
	$(RM) *.o
	$(RM) $(BIN)
	$(RM) *.gch
