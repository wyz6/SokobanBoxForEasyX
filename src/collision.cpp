#include "../include/utils.h"

bool Collision::checkBallBarCollision() {
	// 检查小球是否在挡板的垂直范围内
	if (ball.y + ball.radius < barect.top || ball.y - ball.radius > barect.bottom) {
		return false;
	}

	// 计算小球中心到挡板最近点的距离
	int closest_x = std::clamp(ball.x, barect.left, barect.right);
	int closest_y = barect.top;  // 挡板顶部是唯一可能的垂直碰撞点

	// 计算小球中心到最近点的向量
	int dx = ball.x - closest_x;
	int dy = ball.y - closest_y;

	// 如果距离小于等于小球的半径，则发生碰撞
	if (dx * dx + dy * dy <= ball.radius * ball.radius) {
		// 主要碰撞发生在垂直方向（小球从上往下撞击挡板顶部）
		if (ball.vy > 0 && ball.y + ball.radius >= barect.top) {
			ball.vy = -ball.vy;
			return true;
		}

		// 检查水平方向的碰撞（小球从侧面撞击挡板）
		if (ball.vx > 0 && ball.x + ball.radius >= barect.left && ball.x + ball.radius <= barect.right &&
		        ball.y >= barect.top && ball.y <= barect.bottom) {
			ball.vx = -ball.vx;
			return true;
		}
		if (ball.vx < 0 && ball.x - ball.radius <= barect.right && ball.x - ball.radius >= barect.left &&
		        ball.y >= barect.top && ball.y <= barect.bottom) {
			ball.vx = -ball.vx;
			return true;
		}
	}
	return false;
}

bool Collision::checkBallBrickCollision() {
	for (auto &brick : bricks) {
		if (!brick.exists)
			continue; // 砖块不存在，跳过

		int brick_left = brick.x;
		int brick_right = brick.x + brick.width;
		int brick_top = brick.y;
		int brick_bottom = brick.y + brick.height;

		// 计算小球的四个角点
		int ball_left = ball.x - ball.radius;
		int ball_right = ball.x + ball.radius;
		int ball_top = ball.y - ball.radius;
		int ball_bottom = ball.y + ball.radius;

		// 检查小球是否与砖块的任何部分发生碰撞
		if (ball_bottom >= brick_top && ball_top <= brick_bottom &&
		        ball_right >= brick_left && ball_left <= brick_right) {
			// 计算最近的碰撞点
			int closest_x = std::clamp(ball.x, brick_left, brick_right);
			int closest_y = std::clamp(ball.y, brick_top, brick_bottom);

			// 计算小球到最近碰撞点的距离
			int dx = ball.x - closest_x;
			int dy = ball.y - closest_y;

			// 如果距离小于等于小球的半径，则发生碰撞
			if (dx * dx + dy * dy <= ball.radius * ball.radius) {
				brick.exists = false;
				if (dy > dx) {
					ball.vy = -ball.vy;
				} else {
					ball.vx = -ball.vx;
				}
				return true;
			}
		}
	}
	return false;
}

void Collision::checkBallBoundaryCollision() {
	// 左右边界碰撞
	if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= Game::Width) {
		ball.vx = -ball.vx;
	}

	// 上下边界碰撞
	if (ball.y - ball.radius <= 0) {
		ball.vy = -ball.vy;
	} else if (ball.y + ball.radius >= Game::High) {
		// 游戏结束条件：小球掉出屏幕下方
		GameLogic::gameover();
		exit(0); // 退出程序
	}
}