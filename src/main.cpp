#include "../include/utils.h"
#include <windows.h>
#include <filesystem>
#include <cstdlib>

int currentLevel = 1;

void loadNextLevel() {
	std::string levelInfoPath = "./level_info/";
	std::filesystem::path filename = levelInfoPath + "level_" + std::to_string(currentLevel) + ".txt";

	if (!std::filesystem::exists(filename)) {
		std::cerr << "File does not exist: " << filename << std::endl; // �ļ���������ʾ
		return;
	}

	loadLevel(filename.string()); // ���عؿ��ļ�
	currentLevel++;
}

int main() {
	srand(static_cast<unsigned>(time(nullptr))); // ��ʼ�����������

	std::filesystem::path levelInfoPath = "./level_info";

	std::string command = "python generate_levels.py 10 \"" + levelInfoPath.string() + "\"";
	int result = system(command.c_str());
	if (result != 0) {
		std::cerr << "Failed to run Python script to generate levels." << std::endl; // ����Python�ű�ʧ����ʾ
		return 1;
	}

	startup(); // ������Ϸ
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, TEXT(GAME_TITLE)); // ���ô��ڱ���

	loadNextLevel(); // ���ص�һ��

	DWORD lastTime = GetTickCount();
	const int frameRate = 60;
	const DWORD frameDelay = 1000 / frameRate;

	while (true) {
		DWORD currentTime = GetTickCount();
		DWORD elapsedTime = currentTime - lastTime;

		if (elapsedTime >= frameDelay) {
			lastTime = currentTime;

			clean(); // �����Ļ�ϵĶ���
			updateWithoutInput(); // ������Ϸ״̬�������룩
			updateWithInput(); // �����û�����
			show(); // ��ʾ��Ϸ����

			if (allBricksDestroyed()) {
				outtextxy(Width / 2 - 50, High / 2, "You Win!"); // ��ʾʤ����Ϣ
				FlushBatchDraw(); // ˢ�»�ͼ
				Sleep(2000); // �ӳ�2��

				loadNextLevel(); // ������һ��
				if (bricks.empty())
					break; // ���û�и���ؿ����˳�ѭ��
			}
		} else {
			Sleep(frameDelay - elapsedTime); // ����֡��
		}
	}

	gameover(); // ������Ϸ
	closegraph(); // �ر�ͼ�δ���
	return 0;
}