#include "player.h"

player::player() {

}

void player::jump() {
	std::time_t time = clock();

	if (time - lastJump <= 300) {
		return;
	}

	lastJump = time; 
	velocity += 3;
}

bool test = false;

void player::update() {
	lastHeight = height;
	height -= velocity;

	test = !test;
	if (test) { velocity--; }

	velocity = std::max(-1, std::min(velocity, 3));
	height = std::max(1, std::min(height, 28));

	if (height <= 1 || height >= 28) {
		
	}
}