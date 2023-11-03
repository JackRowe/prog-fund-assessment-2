#pragma once
class pipe
{
private:

public:
	bool direction;
	int length;
	int position;

	pipe(int length, bool direction);
	void update();
	void destroy();
};

