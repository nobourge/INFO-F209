#include"translator.h"

using namespace std;


/// checks move conformity
/// \param move
/// \param lettres
/// \return
bool translator::verifyMove(string move, vector<char> lettres) {
	bool coup_verified = false;
	for (auto x : lettres) {

		if (move[0] == x) {
			coup_verified = true;

		}
	}

	return coup_verified;
}

///
/// \param move
/// \param nombres
/// \return
bool translator::verifyNumber(string move, vector<string> nombres) {
	bool numberVerified = false;
	for (auto x : nombres) {
		int nr = stoi(move);
		if (nr == stoi(x)) {
			numberVerified = true;
		}
	}
	return numberVerified;
}

///
/// \param move
/// \param taille
/// \return
Position translator::translateMove(string move,int taille) {
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

std::string translator::PositionToMove(const Position position, int size){
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
