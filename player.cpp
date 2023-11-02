#include "player.h"

player::player() {

}

void player::jump() {
	std::time_t time = clock();

	if (time - lastJump <= 300) {
		return;
	}

	lastJump = time; 
	velocity += 5;
}

void player::update() {
	lastHeight = height;
	height -= velocity;
	velocity--;
	velocity = std::max(-1, std::min(velocity, 10));
	height = std::max(1, std::min(height, 28));

	if (height <= 1 || height >= 28) {
		
	}
}