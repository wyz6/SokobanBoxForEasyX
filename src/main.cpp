// Sokobanbox/src/main.cpp
#include "../include/utils.h"
#include <windows.h>
#include <filesystem>
#include <cstdlib>

int currentLevel = 1;

void loadNextLevel() {
	std::string levelInfoPath = "./level_info/";
	std::filesystem::path filename = levelInfoPath + "level_" + std::to_string(currentLevel) + ".txt";

	if (!std::filesystem::exists(filename)) {
		std::cerr << "File does not exist: " << filename << std::endl;
		return;
	}

	Level::loadLevel(filename.string());
	currentLevel++;
}

int main() {
	srand(static_cast<unsigned>(time(nullptr)));

	std::filesystem::path levelInfoPath = "./level_info";

	std::string command = "python generate_levels.py 10 \"" + levelInfoPath.string() + "\"";
	int result = system(command.c_str());
	if (result != 0) {
		std::cerr << "Failed to run Python script to generate levels." << std::endl;
		return 1;
	}

	GameLogic::startup();
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, TEXT(GAME_TITLE));

	loadNextLevel();

	DWORD lastTime = GetTickCount();
	const int frameRate = 60;
	const DWORD frameDelay = 1000 / frameRate;

	while (true) {
		DWORD currentTime = GetTickCount();
		DWORD elapsedTime = currentTime - lastTime;

		if (elapsedTime >= frameDelay) {
			lastTime = currentTime;

			Graphics::clean();
			GameLogic::updateWithoutInput();
			Input::updateWithInput();
			Graphics::show();

			if (GameLogic::allBricksDestroyed()) {
				outtextxy(Game::Width / 2 - 50, Game::High / 2, "You Win!");
				FlushBatchDraw();
				Sleep(2000);

				loadNextLevel();
				if (bricks.empty())
					break;
			}
		} else {
			Sleep(frameDelay - elapsedTime);
		}
	}

	GameLogic::gameover();
	closegraph();
	return 0;
}