#pragma once

#include "utils.h"

const int High = 480; // 游戏窗口高度
const int Width = 640; // 游戏窗口宽度
const int Max_Brick_num = 50; // 最大砖块数量

struct Ball {
	int x, y; // 小球位置
	int vx, vy; // 小球速度
	int radius; // 小球半径
};

struct Bar {
	int x, y; // 挡板位置
	int h, w; // 挡板高度和宽度
	int left, right, top, bottom; // 挡板边界
};

struct Brick {
	int x, y; // 砖块位置
	int width, height; // 砖块宽度和高度
	bool exists; // 砖块是否存在
};

extern Ball ball;
extern Bar barect;
extern std::vector<Brick> bricks;