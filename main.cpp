#include "main.h"

void init(CONSOLE_CURSOR_INFO* info, CONSOLE_SCREEN_BUFFER_INFO* screenInfo) {
	// set the cursosr info
	info->dwSize = 100;
	info->bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), info);

	// get screen buffer info
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), screenInfo);

	// output the top and bottom bounds of the game
	std::cout << std::string(120, '-');
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 28 });
	std::cout << std::string(120, '-');

	// prevent fullscreen
	DWORD previousMode;
	GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &previousMode);
	auto newMode = previousMode & (~ENABLE_PROCESSED_INPUT);
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), newMode);

	// prevent resizing
	SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	// setup random
	srand(time(NULL));
}

void setHighscore(int highscore) {
	std::fstream highscoreFile;
	highscoreFile.open("highscore.txt", std::fstream::out);
	highscoreFile << highscore;
	highscoreFile.close();
}

int getHighscore() {
	std::fstream highscoreFile;
	highscoreFile.open("highscore.txt", std::fstream::in);
	int highscore;
	highscoreFile >> highscore;
	
	if (!highscore || highscore < 0) {
		highscore = 0;
	}

	highscoreFile.close();
	return highscore;
}

void outputHeader(COORD position) {
	std::fstream file;
	file.open("header.txt", std::fstream::in);

	for (std::string line; getline(file, line); ) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		position.Y++;
		std::cout << line;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {46, 12});
	std::cout << "highscore: " << getHighscore();
}

void gameLoop(player* user, CONSOLE_SCREEN_BUFFER_INFO* screenInfo) {
	int t = 0;
	int highscore = getHighscore();
	int distance = 40;
	bool dead = false;
	std::vector<pipe> pipes = {};

	pipe newPipe(10, 118, 10);
	pipes.push_back(newPipe);

	while (!dead) {
		t++;

		if (t % 200 == 0 && distance > 10) {
			distance--;
		}

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 29 });

		if (t > highscore) {
			highscore = t;
		}

		std::cout << "score: " << t << " | high score: " << highscore;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), screenInfo);
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), { 120, 20 });

		if (GetAsyncKeyState(32) & 0x8000) {
			user->jump();
		}

		user->update();

		for (int i = 0; i < pipes.size(); i++) {
			pipes[i].update();

			if (pipes[i].position <= 1) {
				pipes.erase(pipes.begin() + i);
			}

			if ((screenInfo->dwSize.X / 2) == pipes[i].position || (screenInfo->dwSize.X / 2) == pipes[i].position + 1) {
				if (user->height > pipes[i].gapHeight && user->height < pipes[i].gapHeight + pipes[i].gapSize) {
					continue;
				}

				dead = true;
			}
		}

		if (t% distance <= 0 ) {
			int addition = (40 - distance);

			pipe newPipe(3 + rand() % (7 + addition), 118, 5 + rand() % 5 + (10 - addition));
			pipes.push_back(newPipe);
		}

		Sleep(66);
	}

	for (pipe i : pipes) {
		i.destroy();
	}

	pipes.clear();

	if (t > getHighscore()) {
		setHighscore(t);
	}
}

void clearPlayable() {
	for (int x = 0; x < 120; x++) {
		for (int y = 1; y < 28; y++) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(x), short(y)});
			std::cout << " ";
		}
	}
}

void clearBottom() {
	for (int x = 0; x < 120; x++) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { short(x), 29 });
		std::cout << " ";
	}
}

int main() {
	player user;
	CONSOLE_CURSOR_INFO info;
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;

	init(&info, &screenInfo);

	int empty = 0;

	while (true) { 
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 60 - 11, 29 });
		std::cout << "PRESS [SPACE] TO START";

		outputHeader({60 - 17,1});

		while (!(GetAsyncKeyState(32) & 0x8000)) {
			Sleep(1);
		}

		user.height = 15;
		clearPlayable(); clearBottom();

		gameLoop(&user, &screenInfo); 
		clearPlayable(); clearBottom(); 
	}
}