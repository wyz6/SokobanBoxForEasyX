#include "../include/utils.h"

bool Collision::checkBallBarCollision() {
	// ���С���Ƿ��ڵ���Ĵ�ֱ��Χ��
	if (ball.y + ball.radius < barect.top || ball.y - ball.radius > barect.bottom) {
		return false;
	}

	// ����С�����ĵ����������ľ���
	int closest_x = std::clamp(ball.x, barect.left, barect.right);
	int closest_y = barect.top;  // ���嶥����Ψһ���ܵĴ�ֱ��ײ��

	// ����С�����ĵ�����������
	int dx = ball.x - closest_x;
	int dy = ball.y - closest_y;

	// �������С�ڵ���С��İ뾶��������ײ
	if (dx * dx + dy * dy <= ball.radius * ball.radius) {
		// ��Ҫ��ײ�����ڴ�ֱ����С���������ײ�����嶥����
		if (ball.vy > 0 && ball.y + ball.radius >= barect.top) {
			ball.vy = -ball.vy;
			return true;
		}

		// ���ˮƽ�������ײ��С��Ӳ���ײ�����壩
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
			continue; // ש�鲻���ڣ�����

		int brick_left = brick.x;
		int brick_right = brick.x + brick.width;
		int brick_top = brick.y;
		int brick_bottom = brick.y + brick.height;

		// ����С����ĸ��ǵ�
		int ball_left = ball.x - ball.radius;
		int ball_right = ball.x + ball.radius;
		int ball_top = ball.y - ball.radius;
		int ball_bottom = ball.y + ball.radius;

		// ���С���Ƿ���ש����κβ��ַ�����ײ
		if (ball_bottom >= brick_top && ball_top <= brick_bottom &&
		        ball_right >= brick_left && ball_left <= brick_right) {
			// �����������ײ��
			int closest_x = std::clamp(ball.x, brick_left, brick_right);
			int closest_y = std::clamp(ball.y, brick_top, brick_bottom);

			// ����С�������ײ��ľ���
			int dx = ball.x - closest_x;
			int dy = ball.y - closest_y;

			// �������С�ڵ���С��İ뾶��������ײ
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
	// ���ұ߽���ײ
	if (ball.x - ball.radius <= 0 || ball.x + ball.radius >= Game::Width) {
		ball.vx = -ball.vx;
	}

	// ���±߽���ײ
	if (ball.y - ball.radius <= 0) {
		ball.vy = -ball.vy;
	} else if (ball.y + ball.radius >= Game::High) {
		// ��Ϸ����������С�������Ļ�·�
		GameLogic::gameover();
		exit(0); // �˳�����
	}
}