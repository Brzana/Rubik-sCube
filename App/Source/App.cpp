#include "Core/Core.h"
#include <iostream>

// trzeba ztestowac GetMove()

int main()
{
	Core::Cube cube;
	cube.PrintCube(cube.state); 
	std::cout << "\n\n";
	cube.MakeMove( 3, cube.state);
	cube.PrintCube(cube.state);
	std::cout << "\n\n";
	cube.MakeMove( 4, cube.state);
	cube.PrintCube(cube.state);
	std::cout << "\n\n";
	cube.MakeMove(21, cube.state);
	cube.PrintCube(cube.state);
	bool isSolved = cube.CheckSolved(cube.state);
	if (isSolved) {
		std::cout << "\n\nKostka jest u�o�ona";
	}
	else {
		std::cout << "\n\nKostka nie jest u�o�ona";
	}
	return 0;
}