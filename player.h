#pragma once
#include <algorithm>
#include <iostream>
#include <windows.h>

class player
{
private:
	std::time_t lastJump = 0;
	int velocity = 0;

public:
	int height = 15;
	int lastHeight = 15;

	player();
	void jump();
	void kill();
	void update();
	void draw();
};

