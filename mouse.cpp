#include "mouse.h"

POINT getMousePosition() {
	POINT position;
	GetCursorPos(&position);

	return position;
}