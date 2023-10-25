#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <vector>

HANDLE const handle = GetStdHandle(STD_OUTPUT_HANDLE);

void runSystem(std::string command);
void setConsoleCursorPosition(COORD position);
void setConsoleTextColor(int color);
void setConsoleBufferSize(COORD size);
void setConsoleSize(COORD size);
void setConsoleFullscreen(bool fullscreen);
void setConsolePosition(COORD position);
HWND getConsole();