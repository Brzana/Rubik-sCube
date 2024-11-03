#include "Core.h"
#include <iostream>

namespace Core {

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

	void Cube::MakeMove(int move, int(&state)[6][3][3]) {
		switch (move) {
		case U:
		{
			shift4(state[TOP][0][1], state[TOP][1][2], state[TOP][1][0], state[TOP][2][1]);
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
		}
	}

}