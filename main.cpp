#include "main.h"


int main() {
	player user;

	// set the cursosr info
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	// get screen buffer info
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);

	// output the top and bottom bounds of the game
	std::cout << std::string(screenInfo.dwSize.X, '-');
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 29 });
	std::cout << std::string(screenInfo.dwSize.X, '-');

	// prevent fullscreen
	DWORD previousMode;
	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &previousMode);
	auto newMode = previousMode & (~ENABLE_PROCESSED_INPUT);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), newMode);

	// prevent resizing
	SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	// list of pipes in the scene
	std::vector<pipe> pipes = {};

	for (int t = 0; t < 1000; t++) {
		// updates the screen buffer size
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), screenInfo.dwSize);

		if (GetKeyState(32) & 0x8000) {
			user.jump();
		}

		user.update();

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(screenInfo.dwSize.X / 2), short(user.lastHeight) });
		std::cout << " ";

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(screenInfo.dwSize.X / 2), short(user.height) });

		std::cout << "O";
		Sleep(66);
	}
}