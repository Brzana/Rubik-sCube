#include "Core/Core.h"
#include <iostream>

// trzeba ztestowac GetMove()

int main()
{
	Core::Cube cube;
	int move = cube.GetMove();
	std::cout << move;
}