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

	void Cube::MakeMove(int move, const int(&state)[6][3][3]) {

	}

}