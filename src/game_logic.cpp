#include "../include/utils.h"

Ball ball;
Bar barect;
std::vector<Brick> bricks;

void initBall() {
	ball.x = Width / 2; // 设置小球初始x坐标为中心
	ball.y = High / 2; // 设置小球初始y坐标为中心
	ball.vx = 5; // 设置小球初始x轴速度
	ball.vy = -5; // 设置小球初始y轴速度
	ball.radius = 10; // 设置小球半径
}

void updateBarBounds() {
	barect.left = barect.x - barect.w / 2; // 计算挡板左边界
	barect.right = barect.x + barect.w / 2; // 计算挡板右边界
	barect.top = barect.y - barect.h / 2; // 计算挡板上边界
	barect.bottom = barect.y + barect.h / 2; // 计算挡板下边界
}

void initBar() {
	barect.h = High / 20; // 设置挡板高度
	barect.w = Width / 4; // 设置挡板宽度
	barect.x = Width / 2; // 设置挡板初始x坐标为中心
	barect.y = High - barect.h / 2; // 设置挡板初始y坐标在底部
	updateBarBounds(); // 更新挡板边界
}

void startup() {
	initBall(); // 初始化小球
	initBar(); // 初始化挡板
	initgraph(Width, High); // 初始化图形窗口
	BeginBatchDraw(); // 开始批量绘图
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, TEXT(GAME_TITLE)); // 设置窗口标题
}

void gameover() {
	EndBatchDraw(); // 结束批量绘图
	closegraph(); // 关闭图形窗口
}

void updateWithoutInput() {
	checkBallBarCollision(); // 检测小球与挡板的碰撞
	checkBallBrickCollision(); // 检测小球与砖块的碰撞
	checkBallBoundaryCollision(); // 检测小球与边界的碰撞
	updateBallPosition(); // 更新小球位置
}

bool allBricksDestroyed() {
	return std::none_of(bricks.begin(), bricks.end(), [](const auto & brick) {
		return brick.exists;
	}); // 检查所有砖块是否被摧毁
}