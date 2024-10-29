#pragma once
#include <vector>

namespace Core {

	void PrintHelloWorld();

	enum colors {W, G, R, B, O, Y};

	enum move { U, Uprim, U2, R, Rprim, R2, L, Lprim, L2, F, Fprim, F2, B, Bprim, B2, D, Dprim, D2, M, Mprim, M2, /*rotacje*/ x, xprim, x2, y, yprim, y2, z, zprim, z2, none };

	class Cube {
	public:
		Cube();
		std::vector<int> state;
		void PrintCube(const std::vector<int>& state);
		std::vector<int> MakeMove(int move, const std::vector<int>& state);
		bool CheckSolved();
		int GetMove();
		std::vector<int> ParseScramble();
		int Hash();
		int GetInverse();
		std::vector<int> Scramble(const std::vector<int>& state);
		Cube operator==(int hash);
	};

}