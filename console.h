#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>

#define DEFAULT_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

void setOuputCursorPosition(COORD position);
void outputFile(std::string file_name, COORD position);
void setOuputColor(int color);