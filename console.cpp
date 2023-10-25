#include "console.h"

HWND window = NULL;

void runSystem(std::string command) {
	char* command_characters{ new char[command.length()] };

	for (int i = 0; i < command.length(); i++) {
		command_characters[i] = command[i]; // could overrun array
	}

	system(command_characters);
	delete[] command_characters;
}

std::string convertSizeToCommand(COORD size) {
	std::string command = "mode ";
	command += std::to_string(size.X);
	command += ",";
	command += std::to_string(size.Y);
	return command;
}

void setConsoleCursorPosition(COORD position) {
	SetConsoleCursorPosition(handle, position);
}

void setConsoleTextColor(int color) {
	SetConsoleTextAttribute(handle, color);
}

void setConsoleBufferSize(COORD size) {
	SetConsoleScreenBufferSize(handle, size);
}

void setConsoleSize(COORD size) {
	std::string system_command = convertSizeToCommand(size);

	runSystem(system_command);
	setConsoleBufferSize(size);
}

void setConsoleFullscreen(bool fullscreen) {
	if (fullscreen) {
		system ("mode 1000");
	}

	system("mode 120,30");
}

HWND getConsole() {
	LPCWSTR title = L"Test";
	SetConsoleTitle(title);

	window = FindWindow(NULL, title);
	return FindWindow(NULL, title);
}

void setConsolePosition(COORD position) {
	if (window == NULL) {
		window = getConsole();
	}

	SetWindowPos(window, NULL, position.X, position.Y, 0, 0, SWP_NOSIZE);
}