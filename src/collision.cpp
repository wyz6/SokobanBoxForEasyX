#include "../include/utils.h"

bool Collision::checkBallBarCollision() {
	if (ball.y + ball.radius < barect.top || ball.y - ball.radius > barect.bottom)
		return false;

	int closest_x = std::clamp(ball.x, barect.left, barect.right);
	int closest_y = barect.top;
	int dx = ball.x - closest_x;
	int dy = ball.y - closest_y;

	if (dx * dx + dy * dy <= ball.radius * ball.radius) {
		ball.vy = -ball.vy;
		return true;
	}
	return false;
}

bool Collision::checkBallBrickCollision() {
	for (auto &brick : bricks) {
		if (!brick.exists)
			continue;

		int brick_left = brick.x;
		int brick_right = brick.x + brick.width;
		int brick_top = brick.y;
		int brick_bottom = brick.y + brick.height;

		if (ball.y + ball.radius >= brick_top && ball.y - ball.radius <= brick_bottom &&
		        ball.x + ball.radius >= brick_left && ball.x - ball.radius <= brick_right) {
			brick.exists = false;
			if (std::abs(ball.vy) > std::abs(ball.vx))
				ball.vy = -ball.vy;
			else
				ball.vx = -ball.vx;
			return true;
		}
	}
	return false;
}

void Collision::checkBallBoundaryCollision() {
	if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= Game::Width)
		ball.vx = -ball.vx;
	if (ball.y - ball.radius <= 0)
		ball.vy = -ball.vy;
	else if (ball.y + ball.radius >= Game::High)
		GameLogic::gameover();
}