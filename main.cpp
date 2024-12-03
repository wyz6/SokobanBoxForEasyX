#include "utils.h"

int currentLevel = 1;

void loadNextLevel() {
	std::string filename = "level_" + std::to_string(currentLevel) + ".txt";
	Level::loadLevel(filename);
	currentLevel++;
}

int main() {
	initgraph(Game::Width, Game::High);
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, TEXT(GAME_TITLE));

	loadNextLevel();

	DWORD lastTime = GetTickCount();
	const int frameRate = 60; // 目标帧率为60 FPS
	const DWORD frameDelay = 1000 / frameRate; // 每帧间隔时间 (毫秒)

	while (true) {
		DWORD currentTime = GetTickCount();
		DWORD elapsedTime = currentTime - lastTime;

		if (elapsedTime >= frameDelay) {
			lastTime = currentTime;

			Graphics::clean();
			GameLogic::updateWithoutInput();
			Input::updateWithInput();
			Graphics::show();

			// 检查是否所有砖块都被消除
			if (GameLogic::allBricksDestroyed()) {
				// 所有砖块都被消除，游戏胜利
				outtextxy(Game::Width / 2 - 50, Game::High / 2, "You Win!");
				FlushBatchDraw();
				Sleep(2000); // 暂停2秒

				// 加载下一个关卡
				loadNextLevel();
				if (bricks.empty()) {
					break; // 没有更多关卡
				}
			}
		} else {
			Sleep(frameDelay - elapsedTime);
		}
	}

	GameLogic::gameover();
	closegraph();
	return 0;
}