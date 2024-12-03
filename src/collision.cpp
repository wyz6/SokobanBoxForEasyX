#include "../include/utils.h"

bool checkBallBarCollision() {
	if (ball.y + ball.radius < barect.top || ball.y - ball.radius > barect.bottom)
		return false; // 检测小球是否在挡板上方或下方

	int closest_x = std::clamp(ball.x, barect.left, barect.right); // 计算最近的x坐标
	int closest_y = barect.top; // 挡板顶部y坐标
	int dx = ball.x - closest_x; // x方向的距离
	int dy = ball.y - closest_y; // y方向的距离

	return dx * dx + dy * dy <= ball.radius * ball.radius ? (ball.vy = -ball.vy,
	        true) : false; // 如果距离小于等于半径，则发生碰撞，反转y轴速度
}

bool checkBallBrickCollision() {
	for (auto &brick : bricks) {
		if (!brick.exists)
			continue; // 跳过不存在的砖块

		int brick_left = brick.x;
		int brick_right = brick.x + brick.width;
		int brick_top = brick.y;
		int brick_bottom = brick.y + brick.height;

		if (ball.y + ball.radius >= brick_top && ball.y - ball.radius <= brick_bottom &&
		        ball.x + ball.radius >= brick_left && ball.x - ball.radius <= brick_right) { // 检测小球是否与砖块相交
			brick.exists = false; // 销毁砖块
			std::abs(ball.vy) > std::abs(ball.vx) ? ball.vy = -ball.vy : ball.vx = -ball.vx; // 根据碰撞角度反转速度
			return true;
		}
	}
	return false;
}

void checkBallBoundaryCollision() {
	if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= Width)
		ball.vx = -ball.vx; // 检测小球是否触碰左右边界，反转x轴速度
	if (ball.y - ball.radius <= 0)
		ball.vy = -ball.vy; // 检测小球是否触碰上边界，反转y轴速度
	else if (ball.y + ball.radius >= High)
		gameover(); // 检测小球是否触碰下边界，结束游戏
}