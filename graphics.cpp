#include "utils.h"

void Graphics::clean() {
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(ball.x, ball.y, ball.radius);  // ���ƺ��ߡ���ɫ����Բ
	bar(barect.left, barect.top, barect.right, barect.bottom); // ���ƺ��ߡ���ɫ���ĵ���

	for (const auto &brick : bricks) {
		if (!brick.exists) { // ש��û���ˣ����ƺ�ɫ
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height);
		}
	}
}

void Graphics::show() {
	setcolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(ball.x, ball.y, ball.radius); // ���ƻ��ߡ���ɫ����Բ
	bar(barect.left, barect.top, barect.right, barect.bottom); // ���ƻ��ߡ���ɫ���ĵ���

	for (const auto &brick : bricks) {
		if (brick.exists) { // ש����ڣ�����ש��
			setcolor(WHITE);
			setfillcolor(RED);
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height); // ����ש��
		}
	}

	FlushBatchDraw();
	Sleep(3); // ��ʱ
}

void Graphics::updateBallPosition() {
	ball.x += ball.vx;
	ball.y += ball.vy;
}