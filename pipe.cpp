#include "pipe.h"

pipe::pipe(int initGapHeight, int initPosition, int initGapSize) {
	gapHeight = initGapHeight;
	position = initPosition;
	gapSize = initGapSize;
}

void pipe::update() {
	lastPosition = position+1;
	position -= 1;

	if (position <= 1) {
		pipe::destroy();
	}
	else {
		pipe::draw();
	}
}

void pipe::draw() {
	// draw the new position
	for (int i = 1; i < 28; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(position), short(i) });
		if (i > gapHeight && i < gapHeight + gapSize) {
			continue;
		}
		else if (i == gapHeight) {
			std::cout << "\\/";
		}
		else if (i == gapHeight + gapSize) {
			std::cout << "/\\";
		}
		else {
			std::cout << "|";
		}
	}
	// undraw last position
	for (int i = 1; i < 28; i++) {
		if (i > gapHeight && i < gapHeight + gapSize) {
			continue;
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(lastPosition), short(i) });
		std::cout << " ";
	}
}

void pipe::destroy() {
	for (int i = 1; i < 28; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(lastPosition), short(i) });
		std::cout << " ";
	}

	for (int i = 1; i < 28; i++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(lastPosition - 1), short(i) });
		std::cout << " ";
	}
}