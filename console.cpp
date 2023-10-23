#include "console.h"

void setOuputCursorPosition(COORD position) {
	SetConsoleCursorPosition(DEFAULT_HANDLE, position);
}

void outputFile(std::string file_name, COORD position) {
	std::fstream file;
	std::string line;

	file.open(file_name);

	if (!file.is_open()) {
		return;
	}

	while (std::getline(file, line)) {
		setOuputCursorPosition(position);
		std::cout << line << std::endl;
		position.Y++;
	}

	file.close();
}

void setOuputColor(int color) {
	SetConsoleTextAttribute(DEFAULT_HANDLE, color);
}