#ifndef GAME_H
#define GAME_H

#include "utils.h"

// 游戏画面尺寸
namespace Game {
	const int High = 480;
	const int Width = 640;
	const int Max_Brick_num = 50;   // 最大砖块个数

	// 结构体定义
	struct Ball {
		int x, y;      // 小球的坐标
		int vx, vy;    // 小球的速度
		int radius;    // 小球的半径
	};

	struct Bar {
		int x, y;      // 挡板中心坐标
		int h, w;      // 挡板的高度和宽度
		int left, right, top, bottom; // 挡板的边界坐标
	};

	struct Brick {
		int x, y;      // 砖块的左上角坐标
		int width, height; // 砖块的宽度和高度
		bool exists;   // 砖块是否存在
	};
}

// 全局变量声明
extern Game::Ball ball;
extern Game::Bar barect;
extern std::vector<Game::Brick> bricks;

#endif // GAME_H