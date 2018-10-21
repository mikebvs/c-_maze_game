CC=g++
CFLAGS=-c -std=c++11
LDFLAGS=-lncurses
SOURCES=main.cpp Console.cpp Coord.cpp Maze.cpp MainMenu.cpp Menu.cpp ChooseSize.cpp Instructions.cpp Saves.cpp Load.cpp Files.cpp ShopScreen.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=maze

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:	
	rm -f *.o $(EXECUTABLE) 
	touch *

handin:
	handin: clean
	handin cmsc162-2 lab10 ../lab10
