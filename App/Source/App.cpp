#include "Core/Core.h"
#include <iostream>

// trzeba ztestowac GetMove()

int main()
{
	Core::Cube cube;
	int move = cube.GetMove();
	std::cout << move;
	std::string lol = "U U";
	std::vector<int> scr = cube.ParseScramble(lol);
}