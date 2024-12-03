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
	const int frameRate = 60; // Ŀ��֡��Ϊ60 FPS
	const DWORD frameDelay = 1000 / frameRate; // ÿ֡���ʱ�� (����)

	while (true) {
		DWORD currentTime = GetTickCount();
		DWORD elapsedTime = currentTime - lastTime;

		if (elapsedTime >= frameDelay) {
			lastTime = currentTime;

			Graphics::clean();
			GameLogic::updateWithoutInput();
			Input::updateWithInput();
			Graphics::show();

			// ����Ƿ�����ש�鶼������
			if (GameLogic::allBricksDestroyed()) {
				// ����ש�鶼����������Ϸʤ��
				outtextxy(Game::Width / 2 - 50, Game::High / 2, "You Win!");
				FlushBatchDraw();
				Sleep(2000); // ��ͣ2��

				// ������һ���ؿ�
				loadNextLevel();
				if (bricks.empty()) {
					break; // û�и���ؿ�
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