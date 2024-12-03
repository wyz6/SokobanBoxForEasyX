#include "../include/utils.h"
#include <windows.h>
#include <iostream> // 添加日志输出
#include <filesystem> // 添加文件系统支持
#include <cstdlib> // 添加 system 函数

int currentLevel = 1;

void loadNextLevel() {
	std::string levelInfoPath = "./level_info/";
	std::filesystem::path absoluteLevelInfoPath = std::filesystem::absolute(levelInfoPath);
	std::filesystem::path filename = absoluteLevelInfoPath / ("level_" + std::to_string(currentLevel) + ".txt");
	std::cout << "Loading level from: " << filename.string() << std::endl; // 日志输出

	// 检查文件是否存在
	if (!std::filesystem::exists(filename)) {
		std::cerr << "File does not exist: " << filename.string() << std::endl;
		return;
	}

	Level::loadLevel(filename.string());
	currentLevel++;
}

int main() {
	srand(static_cast<unsigned>(time(nullptr))); // 初始化随机数种子
	std::cout << "Generating levels..." << std::endl; // 日志输出

	// 获取当前工作目录
	std::filesystem::path currentPath = std::filesystem::current_path();
	std::filesystem::path levelInfoPath = currentPath / "level_info";

	std::cout << "Current working directory: " << currentPath.string() << std::endl;
	std::cout << "Level info path: " << levelInfoPath.string() << std::endl;

	// 使用绝对路径调用 Python 脚本生成关卡信息
	std::string absoluteLevelInfoPath = levelInfoPath.string();
	std::string command = "python generate_levels.py 10 \"" + absoluteLevelInfoPath + "\""; // 使用引号包裹路径以处理空格
	int result = system(command.c_str());
	if (result != 0) {
		std::cerr << "Failed to run Python script to generate levels." << std::endl;
		return 1;
	}

	std::cout << "Levels generated." << std::endl; // 日志输出

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