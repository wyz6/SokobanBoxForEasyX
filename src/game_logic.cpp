#include "../include/utils.h"

Ball ball;
Bar barect;
std::vector<Brick> bricks;

void initBall() {
	ball.x = Width / 2; // ����С���ʼx����Ϊ����
	ball.y = High / 2; // ����С���ʼy����Ϊ����
	ball.vx = 5; // ����С���ʼx���ٶ�
	ball.vy = -5; // ����С���ʼy���ٶ�
	ball.radius = 10; // ����С��뾶
}

void updateBarBounds() {
	barect.left = barect.x - barect.w / 2; // ���㵲����߽�
	barect.right = barect.x + barect.w / 2; // ���㵲���ұ߽�
	barect.top = barect.y - barect.h / 2; // ���㵲���ϱ߽�
	barect.bottom = barect.y + barect.h / 2; // ���㵲���±߽�
}

void initBar() {
	barect.h = High / 20; // ���õ���߶�
	barect.w = Width / 4; // ���õ�����
	barect.x = Width / 2; // ���õ����ʼx����Ϊ����
	barect.y = High - barect.h / 2; // ���õ����ʼy�����ڵײ�
	updateBarBounds(); // ���µ���߽�
}

void startup() {
	initBall(); // ��ʼ��С��
	initBar(); // ��ʼ������
	initgraph(Width, High); // ��ʼ��ͼ�δ���
	BeginBatchDraw(); // ��ʼ������ͼ
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, TEXT(GAME_TITLE)); // ���ô��ڱ���
}

void gameover() {
	EndBatchDraw(); // ����������ͼ
	closegraph(); // �ر�ͼ�δ���
}

void updateWithoutInput() {
	checkBallBarCollision(); // ���С���뵲�����ײ
	checkBallBrickCollision(); // ���С����ש�����ײ
	checkBallBoundaryCollision(); // ���С����߽����ײ
	updateBallPosition(); // ����С��λ��
}

bool allBricksDestroyed() {
	return std::none_of(bricks.begin(), bricks.end(), [](const auto & brick) {
		return brick.exists;
	}); // �������ש���Ƿ񱻴ݻ�
}