

go : main.cpp board.o cell.o Game.o Pawn.o Player.o position.o translator.o wall.o input.o
	g++ main.cpp board.o cell.o Game.o Pawn.o Player.o position.o translator.o wall.o input.o -Wall -Wextra -o go

board.o : models/board.cpp models/board.h
	g++ -c models/board.cpp

cell.o : models/cell.cpp models/cell.h
	g++ -c models/cell.cpp

Game.o : models/Game.cpp models/Game.h
	g++ -c models/Game.cpp

Pawn.o : models/Pawn.cpp models/Pawn.h
	g++ -c models/Pawn.cpp

Player.o : models/Player.cpp models/Player.h
	g++ -c models/Player.cpp

position.o : models/position.cpp models/position.h
	g++ -c models/position.cpp

translator.o : models/translator.cpp models/translator.h
	g++ -c models/translator.cpp

wall.o : models/wall.cpp models/wall.h
	g++ -c models/wall.cpp

input.o : models/input.cpp models/input.h
	g++ -c models/input.cpp
