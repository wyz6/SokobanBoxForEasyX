#include "../include/utils.h"
#include <windows.h>
#include <filesystem>
#include <cstdlib>

int currentLevel = 1;

void loadNextLevel() {
	std::string levelInfoPath = "./level_info/";
	std::filesystem::path filename = levelInfoPath + "level_" + std::to_string(currentLevel) + ".txt";

	if (!std::filesystem::exists(filename)) {
		std::cerr << "File does not exist: " << filename << std::endl; // 文件不存在提示
		return;
	}

	loadLevel(filename.string()); // 加载关卡文件
	currentLevel++;
}

int main() {
	srand(static_cast<unsigned>(time(nullptr))); // 初始化随机数种子

	std::filesystem::path levelInfoPath = "./level_info";

	std::string command = "python generate_levels.py 10 \"" + levelInfoPath.string() + "\"";
	int result = system(command.c_str());
	if (result != 0) {
		std::cerr << "Failed to run Python script to generate levels." << std::endl; // 运行Python脚本失败提示
		return 1;
	}

	startup(); // 启动游戏
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, TEXT(GAME_TITLE)); // 设置窗口标题

	loadNextLevel(); // 加载第一关

	DWORD lastTime = GetTickCount();
	const int frameRate = 60;
	const DWORD frameDelay = 1000 / frameRate;

	while (true) {
		DWORD currentTime = GetTickCount();
		DWORD elapsedTime = currentTime - lastTime;

		if (elapsedTime >= frameDelay) {
			lastTime = currentTime;

			clean(); // 清除屏幕上的对象
			updateWithoutInput(); // 更新游戏状态（无输入）
			updateWithInput(); // 处理用户输入
			show(); // 显示游戏对象

			if (allBricksDestroyed()) {
				outtextxy(Width / 2 - 50, High / 2, "You Win!"); // 显示胜利消息
				FlushBatchDraw(); // 刷新绘图
				Sleep(2000); // 延迟2秒

				loadNextLevel(); // 加载下一关
				if (bricks.empty())
					break; // 如果没有更多关卡，退出循环
			}
		} else {
			Sleep(frameDelay - elapsedTime); // 控制帧率
		}
	}

	gameover(); // 结束游戏
	closegraph(); // 关闭图形窗口
	return 0;
}