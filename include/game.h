#ifndef GAME_H
#define GAME_H

#include "utils.h"

// ��Ϸ����ߴ�
namespace Game {
	const int High = 480;
	const int Width = 640;
	const int Max_Brick_num = 50;   // ���ש�����

	// �ṹ�嶨��
	struct Ball {
		int x, y;      // С�������
		int vx, vy;    // С����ٶ�
		int radius;    // С��İ뾶
	};

	struct Bar {
		int x, y;      // ������������
		int h, w;      // ����ĸ߶ȺͿ��
		int left, right, top, bottom; // ����ı߽�����
	};

	struct Brick {
		int x, y;      // ש������Ͻ�����
		int width, height; // ש��Ŀ�Ⱥ͸߶�
		bool exists;   // ש���Ƿ����
	};
}

// ȫ�ֱ�������
extern Game::Ball ball;
extern Game::Bar barect;
extern std::vector<Game::Brick> bricks;

#endif // GAME_H