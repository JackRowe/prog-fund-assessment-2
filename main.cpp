#include "main.h"


int main(){
	player user;

	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	bool held = false;

	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);
	std::cout << std::string(screenInfo.dwSize.X, '-');
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 29 });
	std::cout << std::string(screenInfo.dwSize.X, '-');

	for (int t = 0; t < 1000; t++) {
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screenInfo);
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), screenInfo.dwSize);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(screenInfo.dwSize.X / 2), short(user.lastHeight) });
		std::cout << " ";
		

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(screenInfo.dwSize.X / 2), short(user.height) });

		if (!held && GetKeyState(32) & 0x8000) {
			user.jump();
			held = true;
		}
		else {
			held = false;
		}

		user.update();

		std::cout << "O";
		Sleep(33);
	}
}