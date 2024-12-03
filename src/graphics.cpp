#include "../include/utils.h"

void clean() {
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(ball.x, ball.y, ball.radius); // ���ƺ�ɫ��������С��
	bar(barect.left, barect.top, barect.right, barect.bottom); // ���ƺ�ɫ�������ǵ���
	for (const auto &brick : bricks)
		if (!brick.exists)
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height); // ���ƺ�ɫ�������������ٵ�ש��
}

void show() {
	setcolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(ball.x, ball.y, ball.radius); // ������ɫ��С��
	bar(barect.left, barect.top, barect.right, barect.bottom); // ���ƻ�ɫ�ĵ���
	for (const auto &brick : bricks)
		if (brick.exists) {
			setcolor(WHITE);
			setfillcolor(RED);
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height); // ���ƺ�ɫ��ש��
		}
	FlushBatchDraw(); // ˢ�»�ͼ
	Sleep(3); // �ӳ�һ��ʱ��
}

void updateBallPosition() {
	ball.x += ball.vx; // ����С��x����
	ball.y += ball.vy; // ����С��y����
}