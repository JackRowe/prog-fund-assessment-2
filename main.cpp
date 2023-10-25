#include "main.h"

// temp include
#include <iostream>

HWND main_window;

int main()
{
	main_window = getConsole();

	for (int n = 0; n < 10; n++) {
		for (short i = 0; i < 1000; i++) {
			setConsolePosition({ i, i });
			Sleep(1);
		}

		for (short i = 1000; i > 0; i--) {
			setConsolePosition({ i, i });
			Sleep(1);
		}
	}
}