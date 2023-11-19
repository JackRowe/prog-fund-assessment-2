#pragma once
#include <Windows.h>
#include <iostream>

class pipe
{
private:

public:
	int gapHeight = 0;
	int gapSize = 0;
	int position = 0;
	int lastPosition = 0;

	pipe(int height, int position, int gapSize);
	void update();
	void draw();
	void destroy();
};

