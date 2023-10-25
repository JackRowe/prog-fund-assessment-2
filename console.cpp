#include "console.h"

HWND window = GetConsoleWindow();
COORD window_position = { 0,0 };

void runSystem(std::string command) {
	char* command_characters{ new char[command.length()] };
	
	for (int i = 0; i < command.length(); i++) {
		command_characters[i] = command[i]; // could overrun array, idk how fix
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
	return GetConsoleWindow();
}

void setConsolePosition(COORD position) {
	if (window == NULL) {
		window = getConsole();
	}

	window_position = position;
	SetWindowPos(window, NULL, position.X, position.Y, 0, 0, SWP_NOSIZE);
}

POINT getConsolePosition() {
	RECT rect = { NULL };

	if (GetWindowRect(window, &rect)) {
		return { rect.right - 30, rect.top + 15 };
	}
}