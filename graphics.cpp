#include "utils.h"

void Graphics::clean() {
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(ball.x, ball.y, ball.radius);  // 绘制黑线、黑色填充的圆
	bar(barect.left, barect.top, barect.right, barect.bottom); // 绘制黑线、黑色填充的挡板

	for (const auto &brick : bricks) {
		if (!brick.exists) { // 砖块没有了，绘制黑色
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height);
		}
	}
}

void Graphics::show() {
	setcolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(ball.x, ball.y, ball.radius); // 绘制黄线、绿色填充的圆
	bar(barect.left, barect.top, barect.right, barect.bottom); // 绘制黄线、绿色填充的挡板

	for (const auto &brick : bricks) {
		if (brick.exists) { // 砖块存在，绘制砖块
			setcolor(WHITE);
			setfillcolor(RED);
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height); // 绘制砖块
		}
	}

	FlushBatchDraw();
	Sleep(3); // 延时
}

void Graphics::updateBallPosition() {
	ball.x += ball.vx;
	ball.y += ball.vy;
}