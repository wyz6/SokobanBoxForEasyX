#pragma once

#include "utils.h"

const int High = 480; // ��Ϸ���ڸ߶�
const int Width = 640; // ��Ϸ���ڿ��
const int Max_Brick_num = 50; // ���ש������

struct Ball {
	int x, y; // С��λ��
	int vx, vy; // С���ٶ�
	int radius; // С��뾶
};

struct Bar {
	int x, y; // ����λ��
	int h, w; // ����߶ȺͿ��
	int left, right, top, bottom; // ����߽�
};

struct Brick {
	int x, y; // ש��λ��
	int width, height; // ש���Ⱥ͸߶�
	bool exists; // ש���Ƿ����
};

extern Ball ball;
extern Bar barect;
extern std::vector<Brick> bricks;