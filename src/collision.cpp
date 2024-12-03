#include "../include/utils.h"

bool checkBallBarCollision() {
	if (ball.y + ball.radius < barect.top || ball.y - ball.radius > barect.bottom)
		return false; // ���С���Ƿ��ڵ����Ϸ����·�

	int closest_x = std::clamp(ball.x, barect.left, barect.right); // ���������x����
	int closest_y = barect.top; // ���嶥��y����
	int dx = ball.x - closest_x; // x����ľ���
	int dy = ball.y - closest_y; // y����ľ���

	return dx * dx + dy * dy <= ball.radius * ball.radius ? (ball.vy = -ball.vy,
	        true) : false; // �������С�ڵ��ڰ뾶��������ײ����תy���ٶ�
}

bool checkBallBrickCollision() {
	for (auto &brick : bricks) {
		if (!brick.exists)
			continue; // ���������ڵ�ש��

		int brick_left = brick.x;
		int brick_right = brick.x + brick.width;
		int brick_top = brick.y;
		int brick_bottom = brick.y + brick.height;

		if (ball.y + ball.radius >= brick_top && ball.y - ball.radius <= brick_bottom &&
		        ball.x + ball.radius >= brick_left && ball.x - ball.radius <= brick_right) { // ���С���Ƿ���ש���ཻ
			brick.exists = false; // ����ש��
			std::abs(ball.vy) > std::abs(ball.vx) ? ball.vy = -ball.vy : ball.vx = -ball.vx; // ������ײ�Ƕȷ�ת�ٶ�
			return true;
		}
	}
	return false;
}

void checkBallBoundaryCollision() {
	if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= Width)
		ball.vx = -ball.vx; // ���С���Ƿ������ұ߽磬��תx���ٶ�
	if (ball.y - ball.radius <= 0)
		ball.vy = -ball.vy; // ���С���Ƿ����ϱ߽磬��תy���ٶ�
	else if (ball.y + ball.radius >= High)
		gameover(); // ���С���Ƿ����±߽磬������Ϸ
}