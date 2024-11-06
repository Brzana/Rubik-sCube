#include "Core/Core.h"
#include <iostream>

int main()
{
	Core::Cube cube;
	cube.PrintCube(cube.state); 
	std::cout << "\n\n";
	cube.MakeMove( 21, cube.state);
	cube.PrintCube(cube.state);
	std::cout << "\n\n";
	cube.MakeMove(3, cube.state);
	cube.PrintCube(cube.state);
	std::cout << "\n\n";
	cube.MakeMove(4, cube.state);
	cube.PrintCube(cube.state);
	return 0;
}