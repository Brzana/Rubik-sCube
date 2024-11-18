#pragma once
#include <vector>
#include <unordered_map>

namespace Core {

	enum colors {w, g, r, b, o, y};

	enum move { U, Uprim, U2, R, Rprim, R2, L, Lprim, L2, F, Fprim, F2, B, Bprim, B2, D, Dprim, D2, M, Mprim, M2, /*rotacje*/ X, Xprim, X2, Y, Yprim, Y2, Z, Zprim, Z2, none };

	enum side { TOP, LEFT, FRONT, RIGHT, BACK, DOWN };

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

	void shift4(int& a, int& b, int& c, int& d);

	void shift4prim(int& a, int& b, int& c, int& d);

	void shiftRotate(int(&state)[6][3][3], int a, int b, int c, int d);

	void shiftRotatePrim(int(&state)[6][3][3], int a, int b, int c, int d);

	class Cube {
	public:
		Cube();
		int state[6][3][3];
		void PrintCube(const int(&state)[6][3][3]);
		void MakeMove(int move, int(&state)[6][3][3]);
		bool CheckSolved(int(&state)[6][3][3]);
		int GetMove();
		std::vector<int> ParseScramble();
		int Hash();
		int GetInverse();
		std::vector<int> Scramble(const std::vector<int>& state);
		Cube operator==(int hash);
	};

}