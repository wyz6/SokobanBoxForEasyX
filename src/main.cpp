#include "../include/utils.h"
#include <windows.h>
#include <iostream> // �����־���
#include <filesystem> // ����ļ�ϵͳ֧��
#include <cstdlib> // ��� system ����

int currentLevel = 1;

void loadNextLevel() {
	std::string levelInfoPath = "./level_info/";
	std::filesystem::path absoluteLevelInfoPath = std::filesystem::absolute(levelInfoPath);
	std::filesystem::path filename = absoluteLevelInfoPath / ("level_" + std::to_string(currentLevel) + ".txt");
	std::cout << "Loading level from: " << filename.string() << std::endl; // ��־���

	// ����ļ��Ƿ����
	if (!std::filesystem::exists(filename)) {
		std::cerr << "File does not exist: " << filename.string() << std::endl;
		return;
	}

	Level::loadLevel(filename.string());
	currentLevel++;
}

int main() {
	srand(static_cast<unsigned>(time(nullptr))); // ��ʼ�����������
	std::cout << "Generating levels..." << std::endl; // ��־���

	// ��ȡ��ǰ����Ŀ¼
	std::filesystem::path currentPath = std::filesystem::current_path();
	std::filesystem::path levelInfoPath = currentPath / "level_info";

	std::cout << "Current working directory: " << currentPath.string() << std::endl;
	std::cout << "Level info path: " << levelInfoPath.string() << std::endl;

	// ʹ�þ���·������ Python �ű����ɹؿ���Ϣ
	std::string absoluteLevelInfoPath = levelInfoPath.string();
	std::string command = "python generate_levels.py 10 \"" + absoluteLevelInfoPath + "\""; // ʹ�����Ű���·���Դ���ո�
	int result = system(command.c_str());
	if (result != 0) {
		std::cerr << "Failed to run Python script to generate levels." << std::endl;
		return 1;
	}

	std::cout << "Levels generated." << std::endl; // ��־���

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