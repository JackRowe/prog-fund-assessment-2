#pragma once
class pipe
{
private:

public:
	int height;
	int size;
	int position;

	pipe(int height, int position, int size);
	void update();
	void destroy();
};

