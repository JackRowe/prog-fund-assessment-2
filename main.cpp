#include "main.h"

// temp include
#include <iostream>

int main()
{

	for (int i = 0; i < 10000; i++) {
		Sleep(1);
		POINT consolePosition = getConsolePosition();
		POINT mousePosition = getMousePosition();
		int difference = sqrt(pow(mousePosition.x - consolePosition.x, 2) + pow(mousePosition.y - consolePosition.y, 2));

		

		//std::cout << "Console: " << consolePosition.X << ", " << consolePosition.Y << std::endl;
		//std::cout << "Mouse: " << mousePosition.x << ", " << mousePosition.y << std::endl;
		std::cout << difference << std::endl;
	}

}