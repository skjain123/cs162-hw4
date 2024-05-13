CC=g++ -std=c++11 -g
exe=asm4

OBJS	= bats.o event.o game.o gold.o main.o room.o stalactites.o wumpus.o
SOURCE	= bats.cpp event.cpp game.cpp gold.cpp main.cpp room.cpp stalactites.cpp wumpus.cpp
HEADER	= bats.h event.h game.h gold.h room.h stalactites.h wumpus.h
OUT	= asm4
CC	 = g++ -std=c++11 -g
FLAGS	 = -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

bats.o: bats.cpp
	$(CC) $(FLAGS) bats.cpp 

event.o: event.cpp
	$(CC) $(FLAGS) event.cpp 

game.o: game.cpp
	$(CC) $(FLAGS) game.cpp 

gold.o: gold.cpp
	$(CC) $(FLAGS) gold.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

room.o: room.cpp
	$(CC) $(FLAGS) room.cpp 

stalactites.o: stalactites.cpp
	$(CC) $(FLAGS) stalactites.cpp 

wumpus.o: wumpus.cpp
	$(CC) $(FLAGS) wumpus.cpp 

clean:
	rm -f $(OBJS) $(OUT)