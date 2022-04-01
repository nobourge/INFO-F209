#include "translator.h"

using namespace std;


Translator Translator::instance;

Translator& Translator::Get() {
	return instance;
}

/// checks move conformity
/// \param move
/// \param lettres
/// \return
bool Translator::verifyMove(string move, vector<char> lettres) {
	for (auto x : lettres) {
		if (move[0] == x) {
			return true;
		}
	}
	return false;
}

///
/// \param move
/// \param nombres
/// \return
bool Translator::verifyNumber(string move, vector<string> nombres) {
	for (auto x : nombres) {
		int nr = stoi(move);
		if (nr == stoi(x)) {
			return true;
		}
	}
	return false;
}

///
/// \param move
/// \param taille
/// \return
Position Translator::translateMove(string move,int taille) {
	Position res;
	vector<char>lettres;
	vector<string>nombres;
	string numb = move.substr(1); // number
	for (int x = 0; x < taille; x++) {
		 lettres.push_back(char(x + int('a')));
	}
	for (int x = 1; x < taille + 1; x++) {
		nombres.push_back(to_string(x));
	}

	if (move.length() < 2 || !verifyMove(move, lettres) || !verifyNumber(numb, nombres)) {
      // not conform
		return {-1,-1};
	}
	else {
		for (int x = 0; x < taille; x++) {
			if (move[0] == lettres[x]) {
				res.row = x;
			}
		}
		for (int x = 0; x < taille; x++) {
			int nr = stoi(numb);
			if (nr == stoi(nombres[x])) {
				res.col = x;
			}
		}

	}

    return res;

}

std::string Translator::PositionToMove(const Position position, int size){
	vector<char>lettres;
	vector<string>nombres;

	for (int x = 0; x < size; x++) {
		lettres.push_back(char(x + int('a')));
	}
	for (int x = 1; x < size + 1; x++) {
		nombres.push_back(to_string(x));
	}

	return lettres[position.row] + nombres[position.col];

}

std::string Translator::PositionToWallMove(Position firstWall, Position SecondWall) {

	std::string direction;
	if (firstWall.col == 0 || SecondWall.col == 0 || abs(firstWall.diff(SecondWall).second) > 0 ) direction = "S";
	else if(firstWall.col == kBoardSize*2-1 || SecondWall.col == kBoardSize*2-1) direction = "W";
	else if(firstWall.row == 0 || SecondWall.row == 0 || abs(firstWall.diff(SecondWall).first) > 0 ) direction = "E";
	else if(firstWall.row == kBoardSize*2-1 || SecondWall.row == kBoardSize*2-1) direction = "N";

	
	return "W->"+PositionToMove({firstWall.col/2, firstWall.row/2}, kBoardSize)+"->"+PositionToMove({SecondWall.col/2, SecondWall.row/2}, kBoardSize)+"->"+direction;
}


DIRECTION Translator::GetOppositeDirection(DIRECTION direction) {
	switch (direction) {
		case NORTH:
			return SOUTH;
		case EAST:
			return WEST;
		case SOUTH: 
			return NORTH;
		case WEST:
			return EAST;
	}
}

std::string Translator::PositionToPawnMove(DIRECTION movementDirection, DIRECTION winningDirection) {
	std::string playerMovementDirection;
	if (movementDirection == winningDirection) playerMovementDirection = "F";
	else if (movementDirection == GetOppositeDirection(winningDirection)) playerMovementDirection = "B";
	else if (movementDirection == EAST && winningDirection == SOUTH) playerMovementDirection = "L";
	else if (movementDirection == WEST && winningDirection == SOUTH) playerMovementDirection = "R";
	else if (movementDirection == EAST && winningDirection == NORTH) playerMovementDirection = "R";
	else if (movementDirection == WEST && winningDirection == NORTH) playerMovementDirection = "L";
	return "M->"+playerMovementDirection;



}