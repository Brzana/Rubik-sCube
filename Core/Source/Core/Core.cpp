#include "Core.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>	
#include <cassert>

namespace Core {
	
	std::unordered_map<std::string, move> moveMap = {
		{"U", U}, {"Uprim", Uprim}, {"U2", U2},
		{"R", R}, {"Rprim", Rprim}, {"R2", R2},
		{"L", L}, {"Lprim", Lprim}, {"L2", L2},
		{"F", F}, {"Fprim", Fprim}, {"F2", F2},
		{"B", B}, {"Bprim", Bprim}, {"B2", B2},
		{"D", D}, {"Dprim", Dprim}, {"D2", D2},
		{"M", M}, {"Mprim", Mprim}, {"M2", M2},
		{"X", X}, {"Xprim", Xprim}, {"X2", X2},
		{"Y", Y}, {"Yprim", Yprim}, {"Y2", Y2},
		{"Z", Z}, {"Zprim", Zprim}, {"Z2", Z2},
		{"none", none}
	};

	Cube::Cube() {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					state[TOP][i][j] = w;
					state[FRONT][i][j] = g;
					state[RIGHT][i][j] = r;
					state[BACK][i][j] = b;
					state[LEFT][i][j] = o;
					state[DOWN][i][j] = y;
				}

			}
		}

	void Cube::PrintCube(const int(&state)[6][3][3]) {
		int i, j, k;
		
		for (i = 0; i < 3; i++) {
			std::cout << "    ";
			for (j = 0; j < 3; j++) {
				std::cout << state[0][i][j];
			}
			std::cout << "\n";
		}

		for (i = 0; i < 3; i++) {
			for (j = 1; j < 5; j++) {
				if (j != 1) {
					std::cout << " ";
				}
				for (k = 0; k < 3; k++) {
					std::cout << state[j][i][k];
				}
			}
			std::cout << "\n";
		}

		for (i = 0; i < 3; i++) {
			std::cout << "    ";
			for (j = 0; j < 3; j++) {
				std::cout << state[5][i][j];
			}
			std::cout << "\n";
		}
	}

	void shift4(int& a, int& b, int& c, int& d) {
		int temp = d;
		d = c;
		c = b;
		b = a;
		a = temp;
	}

	void shift4prim(int& a, int& b, int& c, int& d) {
		int temp = a;
		a = b;
		b = c;
		c = d;
		d = temp;
	}

	void shiftRotate(int (&state)[6][3][3], int a, int b, int c, int d) {
		int temp[3][3];
		std::memcpy(temp, state[a], sizeof(temp));
		std::memcpy(state[a], state[b], sizeof(temp));
		std::memcpy(state[b], state[c], sizeof(temp));
		std::memcpy(state[c], state[d], sizeof(temp));
		std::memcpy(state[d], temp, sizeof(temp));
	}

	void shiftRotatePrim(int(&state)[6][3][3], int d, int c, int b, int a) {
		int temp[3][3];
		std::memcpy(temp, state[a], sizeof(temp));
		std::memcpy(state[a], state[b], sizeof(temp));
		std::memcpy(state[b], state[c], sizeof(temp));
		std::memcpy(state[c], state[d], sizeof(temp));
		std::memcpy(state[d], temp, sizeof(temp));
	}

	void Cube::MakeMove(int move, int(&state)[6][3][3]) {
		switch (move) {
		case U:
		{
			shift4(state[TOP][0][1], state[TOP][1][2], state[TOP][2][1], state[TOP][1][0]);
			shift4(state[BACK][0][1], state[RIGHT][0][1], state[FRONT][0][1], state[LEFT][0][1]);
			shift4(state[TOP][0][0], state[TOP][0][2], state[TOP][2][2], state[TOP][2][0]);
			shift4(state[BACK][0][2], state[RIGHT][0][2], state[FRONT][0][2], state[LEFT][0][2]);
			shift4(state[LEFT][0][0], state[BACK][0][0], state[RIGHT][0][0], state[FRONT][0][0]);
			break;
		}
		case Uprim:
		{
			shift4prim(state[TOP][0][1], state[TOP][1][2], state[TOP][1][0], state[TOP][2][1]);
			shift4prim(state[BACK][0][1], state[RIGHT][0][1], state[FRONT][0][1], state[LEFT][0][1]);
			shift4prim(state[TOP][0][0], state[TOP][0][2], state[TOP][2][2], state[TOP][2][0]);
			shift4prim(state[BACK][0][2], state[RIGHT][0][2], state[FRONT][0][2], state[LEFT][0][2]);
			shift4prim(state[LEFT][0][0], state[BACK][0][0], state[RIGHT][0][0], state[FRONT][0][0]);
			break;
		}
		case U2:
			for (int i = 0; i < 2; i++) {
				shift4(state[TOP][0][1], state[TOP][1][2], state[TOP][1][0], state[TOP][2][1]);
				shift4(state[BACK][0][1], state[RIGHT][0][1], state[FRONT][0][1], state[LEFT][0][1]);
				shift4(state[TOP][0][0], state[TOP][0][2], state[TOP][2][2], state[TOP][2][0]);
				shift4(state[BACK][0][2], state[RIGHT][0][2], state[FRONT][0][2], state[LEFT][0][2]);
				shift4(state[LEFT][0][0], state[BACK][0][0], state[RIGHT][0][0], state[FRONT][0][0]);
			}
			break;
		case R:
			shift4(state[TOP][1][2], state[BACK][1][0], state[DOWN][1][2], state[FRONT][1][2]);
			shift4(state[RIGHT][0][1], state[RIGHT][1][2], state[RIGHT][2][1], state[RIGHT][1][0]);
			shift4(state[TOP][2][2], state[BACK][0][0], state[DOWN][2][2], state[FRONT][2][2]);
			shift4(state[FRONT][0][2], state[TOP][0][2], state[BACK][2][0], state[DOWN][0][2]);
			shift4(state[RIGHT][0][0], state[RIGHT][0][2], state[RIGHT][2][2], state[RIGHT][2][0]);
			break;
		case Rprim:
			shift4prim(state[TOP][1][2], state[BACK][1][0], state[DOWN][1][2], state[FRONT][1][2]);
			shift4prim(state[RIGHT][0][1], state[RIGHT][1][2], state[RIGHT][2][1], state[RIGHT][1][0]);
			shift4prim(state[TOP][2][2], state[BACK][0][0], state[DOWN][2][2], state[FRONT][2][2]);
			shift4prim(state[FRONT][0][2], state[TOP][0][2], state[BACK][2][0], state[DOWN][0][2]);
			shift4prim(state[RIGHT][0][0], state[RIGHT][0][2], state[RIGHT][2][2], state[RIGHT][2][0]);
			break;
		case R2:
			for (int i = 0; i < 2; i++) {
				shift4(state[TOP][1][2], state[BACK][1][0], state[DOWN][1][2], state[FRONT][1][2]);
				shift4(state[RIGHT][0][1], state[RIGHT][1][2], state[RIGHT][2][1], state[RIGHT][1][0]);
				shift4(state[TOP][2][2], state[BACK][0][0], state[DOWN][2][2], state[FRONT][2][2]);
				shift4(state[FRONT][0][2], state[TOP][0][2], state[BACK][2][0], state[DOWN][0][2]);
				shift4(state[RIGHT][0][0], state[RIGHT][0][2], state[RIGHT][2][2], state[RIGHT][2][0]);
			}
			break;
		case L:
			shift4(state[TOP][1][0], state[FRONT][1][0], state[DOWN][1][0], state[BACK][1][2]);
			shift4(state[LEFT][0][1], state[LEFT][1][2], state[LEFT][2][1], state[LEFT][1][0]);
			shift4(state[TOP][0][0], state[FRONT][0][0], state[DOWN][0][0], state[BACK][2][2]);
			shift4(state[BACK][0][2], state[TOP][2][0], state[FRONT][2][0], state[DOWN][2][0]);
			shift4(state[LEFT][0][0], state[LEFT][0][2], state[LEFT][2][2], state[LEFT][2][0]);
			break;
		case Lprim:
			shift4prim(state[TOP][1][0], state[FRONT][1][0], state[DOWN][1][0], state[BACK][1][2]);
			shift4prim(state[LEFT][0][1], state[LEFT][1][2], state[LEFT][2][1], state[LEFT][1][0]);
			shift4prim(state[TOP][0][0], state[FRONT][0][0], state[DOWN][0][0], state[BACK][2][2]);
			shift4prim(state[BACK][0][2], state[TOP][2][0], state[FRONT][2][0], state[DOWN][2][0]);
			shift4prim(state[LEFT][0][0], state[LEFT][0][2], state[LEFT][2][2], state[LEFT][2][0]);
			break;
		case L2:
			for (int i = 0; i < 2; i++) {
				shift4(state[TOP][1][0], state[FRONT][1][0], state[DOWN][1][0], state[BACK][1][2]);
				shift4(state[LEFT][0][1], state[LEFT][1][2], state[LEFT][2][1], state[LEFT][1][0]);
				shift4(state[TOP][0][0], state[FRONT][0][0], state[DOWN][0][0], state[BACK][2][2]);
				shift4(state[BACK][0][2], state[TOP][2][0], state[FRONT][2][0], state[DOWN][2][0]);
				shift4(state[LEFT][0][0], state[LEFT][0][2], state[LEFT][2][2], state[LEFT][2][0]);
			}
			break;
		case F:
			shift4(state[TOP][2][1], state[RIGHT][1][0], state[DOWN][0][1], state[LEFT][1][2]);
			shift4(state[FRONT][0][1], state[FRONT][1][2], state[FRONT][2][1], state[FRONT][1][0]);
			shift4(state[TOP][2][0], state[RIGHT][0][0], state[DOWN][0][2], state[LEFT][2][2]);
			shift4(state[LEFT][0][2], state[TOP][2][2], state[RIGHT][2][0], state[DOWN][0][0]);
			shift4(state[FRONT][0][0], state[FRONT][0][2], state[FRONT][2][2], state[FRONT][2][0]);
			break;
		case Fprim:
			shift4prim(state[TOP][2][1], state[RIGHT][1][0], state[DOWN][0][1], state[LEFT][1][2]);
			shift4prim(state[FRONT][0][1], state[FRONT][1][2], state[FRONT][2][1], state[FRONT][1][0]);
			shift4prim(state[TOP][2][0], state[RIGHT][0][0], state[DOWN][0][2], state[LEFT][2][2]);
			shift4prim(state[LEFT][0][2], state[TOP][2][2], state[RIGHT][2][0], state[DOWN][0][0]);
			shift4prim(state[FRONT][0][0], state[FRONT][0][2], state[FRONT][2][2], state[FRONT][2][0]);
			break;
		case F2:
			for (int i = 0; i < 2; i++) {
				shift4(state[TOP][2][1], state[RIGHT][1][0], state[DOWN][0][1], state[LEFT][1][2]);
				shift4(state[FRONT][0][1], state[FRONT][1][2], state[FRONT][2][1], state[FRONT][1][0]);
				shift4(state[TOP][2][0], state[RIGHT][0][0], state[DOWN][0][2], state[LEFT][2][2]);
				shift4(state[LEFT][0][2], state[TOP][2][2], state[RIGHT][2][0], state[DOWN][0][0]);
				shift4(state[FRONT][0][0], state[FRONT][0][2], state[FRONT][2][2], state[FRONT][2][0]);
				
			}
			break;
		case B:
			shift4(state[TOP][0][1], state[LEFT][1][0], state[DOWN][2][1], state[RIGHT][1][2]);
			shift4(state[BACK][0][1], state[BACK][1][2], state[BACK][2][1], state[BACK][1][0]);
			shift4(state[TOP][0][0], state[LEFT][2][0], state[DOWN][2][2], state[RIGHT][0][2]);
			shift4(state[LEFT][0][0], state[DOWN][2][0], state[RIGHT][2][2], state[TOP][0][2]);
			shift4(state[BACK][0][2], state[BACK][2][2], state[BACK][2][0], state[BACK][0][0]);
			break;
		case Bprim:
			shift4prim(state[TOP][0][1], state[LEFT][1][0], state[DOWN][2][1], state[RIGHT][1][2]);
			shift4prim(state[BACK][0][1], state[BACK][1][2], state[BACK][2][1], state[BACK][1][0]);
			shift4prim(state[TOP][0][0], state[LEFT][2][0], state[DOWN][2][2], state[RIGHT][0][2]);
			shift4prim(state[LEFT][0][0], state[DOWN][2][0], state[RIGHT][2][2], state[TOP][0][2]);
			shift4prim(state[BACK][0][2], state[BACK][2][2], state[BACK][2][0], state[BACK][0][0]);
			break;
		case B2:
			for (int i = 0; i < 2; i++) {
				shift4(state[TOP][0][1], state[LEFT][1][0], state[DOWN][2][1], state[RIGHT][1][2]);
				shift4(state[BACK][0][1], state[BACK][1][2], state[BACK][2][1], state[BACK][1][0]);
				shift4(state[TOP][0][0], state[LEFT][2][0], state[DOWN][2][2], state[RIGHT][0][2]);
				shift4(state[LEFT][0][0], state[DOWN][2][0], state[RIGHT][2][2], state[TOP][0][2]);
				shift4(state[BACK][0][2], state[BACK][2][2], state[BACK][2][0], state[BACK][0][0]);
			}
			break;
		case D:
			shift4(state[DOWN][0][1], state[DOWN][1][2], state[DOWN][2][1], state[DOWN][1][0]);
			shift4(state[FRONT][2][1], state[RIGHT][2][1], state[BACK][2][1], state[LEFT][2][1]);
			shift4(state[FRONT][2][0], state[RIGHT][2][0], state[BACK][2][0], state[LEFT][2][0]);
			shift4(state[LEFT][2][2], state[FRONT][2][2], state[RIGHT][2][2], state[BACK][2][2]);
			shift4(state[DOWN][0][0], state[DOWN][0][2], state[DOWN][2][2], state[DOWN][2][0]);
			break;
		case Dprim:
			shift4prim(state[DOWN][0][1], state[DOWN][1][2], state[DOWN][2][1], state[DOWN][1][0]);
			shift4prim(state[FRONT][2][1], state[RIGHT][2][1], state[BACK][2][1], state[LEFT][2][1]);
			shift4prim(state[FRONT][2][0], state[RIGHT][2][0], state[BACK][2][0], state[LEFT][2][0]);
			shift4prim(state[LEFT][2][2], state[FRONT][2][2], state[RIGHT][2][2], state[BACK][2][2]);
			shift4prim(state[DOWN][0][0], state[DOWN][0][2], state[DOWN][2][2], state[DOWN][2][0]);
			break;
		case D2:
			for (int i = 0; i < 2; i++) {
				shift4(state[DOWN][0][1], state[DOWN][1][2], state[DOWN][2][1], state[DOWN][1][0]);
				shift4(state[FRONT][2][1], state[RIGHT][2][1], state[BACK][2][1], state[LEFT][2][1]);
				shift4(state[FRONT][2][0], state[RIGHT][2][0], state[BACK][2][0], state[LEFT][2][0]);
				shift4(state[LEFT][2][2], state[FRONT][2][2], state[RIGHT][2][2], state[BACK][2][2]);
				shift4(state[DOWN][0][0], state[DOWN][0][2], state[DOWN][2][2], state[DOWN][2][0]);
			}
			break;
		case M:
			shift4(state[TOP][2][1], state[BACK][0][1], state[DOWN][2][1], state[FRONT][2][1]);
			shift4(state[FRONT][0][1], state[TOP][0][1], state[BACK][2][1], state[DOWN][0][1]);
			shift4(state[TOP][1][1], state[BACK][1][1], state[DOWN][1][1], state[FRONT][1][1]);
			break;
		case Mprim:
			shift4prim(state[TOP][2][1], state[BACK][0][1], state[DOWN][2][1], state[FRONT][2][1]);
			shift4prim(state[FRONT][0][1], state[TOP][0][1], state[BACK][2][1], state[DOWN][0][1]);
			shift4prim(state[TOP][1][1], state[BACK][1][1], state[DOWN][1][1], state[FRONT][1][1]);
			break;
		case M2:
			for (int i = 0; i < 2; i++) {
				shift4(state[TOP][2][1], state[BACK][0][1], state[DOWN][2][1], state[FRONT][2][1]);
				shift4(state[FRONT][0][1], state[TOP][0][1], state[BACK][2][1], state[DOWN][0][1]);
				shift4(state[TOP][1][1], state[BACK][1][1], state[DOWN][1][1], state[FRONT][1][1]);
			}
			break;
		case X:
			//int temp[3][3];
			//std::memcpy(temp, state[TOP], sizeof(temp));
			//std::memcpy(state[TOP], state[BACK], sizeof(temp));
			//std::memcpy(state[BACK], state[DOWN], sizeof(temp));
			//std::memcpy(state[DOWN], state[FRONT], sizeof(temp));
			//std::memcpy(state[FRONT], temp, sizeof(temp));
			shiftRotate(state, TOP, BACK, DOWN, FRONT);
			shift4(state[RIGHT][0][1], state[RIGHT][1][2], state[RIGHT][2][1], state[RIGHT][1][0]);
			shift4(state[RIGHT][0][0], state[RIGHT][0][2], state[RIGHT][2][2], state[RIGHT][2][0]);
			shift4(state[LEFT][0][1], state[LEFT][1][0], state[LEFT][2][1], state[LEFT][1][2]);
			shift4(state[LEFT][0][0], state[LEFT][2][0], state[LEFT][2][2], state[LEFT][0][2]);
			break;
		case Xprim:
			int temp[3][3];
			//std::memcpy(temp, state[TOP], sizeof(temp));
			//std::memcpy(state[TOP], state[FRONT], sizeof(temp));
			//std::memcpy(state[FRONT], state[DOWN], sizeof(temp));
			//std::memcpy(state[DOWN], state[BACK], sizeof(temp));
			//std::memcpy(state[BACK], temp, sizeof(temp));
			shiftRotatePrim(state, TOP, BACK, DOWN, FRONT);
			shift4prim(state[RIGHT][0][1], state[RIGHT][1][2], state[RIGHT][2][1], state[RIGHT][1][0]);
			shift4prim(state[RIGHT][0][0], state[RIGHT][0][2], state[RIGHT][2][2], state[RIGHT][2][0]);
			shift4prim(state[LEFT][0][1], state[LEFT][1][0], state[LEFT][2][1], state[LEFT][1][2]);
			shift4prim(state[LEFT][0][0], state[LEFT][2][0], state[LEFT][2][2], state[LEFT][0][2]);
			break;
		case X2:
			for (int i = 0; i < 2; i++) {
				shiftRotate(state, TOP, BACK, DOWN, FRONT);
				shift4(state[RIGHT][0][1], state[RIGHT][1][2], state[RIGHT][2][1], state[RIGHT][1][0]);
				shift4(state[RIGHT][0][0], state[RIGHT][0][2], state[RIGHT][2][2], state[RIGHT][2][0]);
				shift4(state[LEFT][0][1], state[LEFT][1][0], state[LEFT][2][1], state[LEFT][1][2]);
				shift4(state[LEFT][0][0], state[LEFT][2][0], state[LEFT][2][2], state[LEFT][0][2]);
			}
			break;
		case Y:
			shiftRotate(state, FRONT, RIGHT, BACK, LEFT);
			shift4(state[TOP][0][1], state[TOP][1][2], state[TOP][2][1], state[TOP][1][0]);
			shift4(state[TOP][0][0], state[TOP][0][2], state[TOP][2][2], state[TOP][2][0]);
			shift4(state[DOWN][0][1], state[DOWN][1][0], state[DOWN][2][1], state[DOWN][1][2]);
			shift4(state[DOWN][0][0], state[DOWN][2][0], state[DOWN][2][2], state[DOWN][0][2]);
			break;
		case Yprim:
			shiftRotatePrim(state, FRONT, RIGHT, BACK, LEFT);
			shift4prim(state[TOP][0][1], state[TOP][1][2], state[TOP][2][1], state[TOP][1][0]);
			shift4prim(state[TOP][0][0], state[TOP][0][2], state[TOP][2][2], state[TOP][2][0]);
			shift4prim(state[DOWN][0][1], state[DOWN][1][0], state[DOWN][2][1], state[DOWN][1][2]);
			shift4prim(state[DOWN][0][0], state[DOWN][2][0], state[DOWN][2][2], state[DOWN][0][2]);
			break;
		case Y2:
			for (int i = 0; i < 2; i++) {
				shiftRotate(state, FRONT, RIGHT, BACK, LEFT);
				shift4(state[TOP][0][1], state[TOP][1][2], state[TOP][2][1], state[TOP][1][0]);
				shift4(state[TOP][0][0], state[TOP][0][2], state[TOP][2][2], state[TOP][2][0]);
				shift4(state[DOWN][0][1], state[DOWN][1][0], state[DOWN][2][1], state[DOWN][1][2]);
				shift4(state[DOWN][0][0], state[DOWN][2][0], state[DOWN][2][2], state[DOWN][0][2]);
			}
			break;
		case Z:
			break; // nie wiem jak to zrobic zeby dzialalo (zle przechodzi TOP na RIGHT), ale jakims cudem inne funkcje dzialaja dobrze
		}
	}

	bool Cube::CheckSolved(int(&state)[6][3][3]) {
		for (int face = 0; face < 6; face++) {
			int color = state[face][0][0];
			for (int row = 0; row < 3; row++) {
				for (int col = 0; col < 3; col++) {
					if (state[face][row][col] != color) {
						return false;
					}
				}
			}
		}
		return true;
	}

	bool Cube::CheckEnum(const std::string& key, move& out, const std::unordered_map<std::string, move>& moveMap) {
		auto it = moveMap.find(key); 
		if (it != moveMap.end()) {  
			out = it->second;       
			return true;            
		}
		return false;               
	}


	//gdzies jest blad
	int Cube::GetMove() {
		std::string moveString;
		move out;
		std::cout << "Podaj ruch który chcesz wykonaæ (np. U lub U')  ";
		std::cin >> moveString;

		if (Cube::CheckEnum(moveString, out, moveMap)) {
			return static_cast<int>(out);
		}
		else {
			std::cout << "Nieprawid³owy ruch";
			return -1;
		}
	}

		
	//}
	//gdzies jest blad
	//std::vector<int> Cube::ParseScramble(std::string& scramble) {
		//std::vector<int> ParsedScramble;
		//std::istringstream iss(scramble);
		//std::string moveStr;
		//while (iss >> moveStr) {
			//auto it = moveMap.find(moveStr);
			//if (it != moveMap.end()) {
				//int move = static_cast<int>(it->second);
				//ParsedScramble.emplace_back(move);
			//}
			//else {
				//std::cout << "Nieprawid³owy ruch: " << moveStr << "\n";
				// Handle invalid move if necessary
			//}
		//}
		//return ParsedScramble;
	//}

}