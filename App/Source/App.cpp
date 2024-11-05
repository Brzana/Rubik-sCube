#include "Core/Core.h"
#include <iostream>

int main()
{
	Core::Cube cube;
	cube.PrintCube(cube.state); 
	std::cout << "\n\n";
	cube.MakeMove( 6, cube.state);
	cube.PrintCube(cube.state);
	std::cout << "\n\n";
	cube.MakeMove(0, cube.state);
	cube.PrintCube(cube.state);
	std::cout << "\n\n";
	cube.MakeMove(4, cube.state);
	cube.PrintCube(cube.state);
	return 0;
}