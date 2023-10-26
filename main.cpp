#include "main.h"

// temp include
#include <iostream>



int main()
{

	for (int i = 0; i < 100000; i++) {
		Sleep(0.1);
		POINT consolePosition = getConsolePosition();
		POINT mousePosition = getMousePosition();
		COORD consoleSize = getConsoleSize();
		//COORD differenceCoord = consolePosition - mousePosition;
		int difference = sqrt(pow(mousePosition.x - consolePosition.x, 2) + pow(mousePosition.y - consolePosition.y, 2));

		std::cout << difference << std::endl;
		setConsolePosition({ short((mousePosition.x + consoleSize.X) + 30 ), short(mousePosition.y - 15) });
	}

}