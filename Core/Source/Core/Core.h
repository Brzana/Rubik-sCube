#pragma once
#include <vector>
#include <unordered_map>
#include <string>


namespace Core {

	enum colors { w, g, r, b, o, y };

	enum move { U, Uprim, U2, R, Rprim, R2, L, Lprim, L2, F, Fprim, F2, B, Bprim, B2, D, Dprim, D2, M, Mprim, M2, /*rotacje*/ X, Xprim, X2, Y, Yprim, Y2, Z, Zprim, Z2, none };

	enum side { TOP, LEFT, FRONT, RIGHT, BACK, DOWN };

	void shift4(int& a, int& b, int& c, int& d);

	void shift4prim(int& a, int& b, int& c, int& d);

	void shiftRotate(int(&state)[6][3][3], int a, int b, int c, int d);

	void shiftRotatePrim(int(&state)[6][3][3], int a, int b, int c, int d);

	class Cube {
	public:
		Cube();
		int state[6][3][3];
		std::unordered_map<std::string, move> moveMap;
		void PrintCube(const int(&state)[6][3][3]);
		void MakeMove(int move, int(&state)[6][3][3]);
		bool CheckSolved(int(&state)[6][3][3]);
		int GetMove();
		std::vector<int> ParseScramble(std::string& scramble);
		int Hash();
		int GetInverse();
		std::vector<int> Scramble(const std::vector<int>& state);
		Cube operator==(int hash);
		//test
		void TestGetMove_ValidInput();
		void TestGetMove_InvalidInput();
		bool CheckEnum(const std::string& key, move& out, const std::unordered_map<std::string, move>& moveMap);
	};

}