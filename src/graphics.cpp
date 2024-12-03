#include "../include/utils.h"

void Graphics::clean() {
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(ball.x, ball.y, ball.radius);
	bar(barect.left, barect.top, barect.right, barect.bottom);
	for (const auto &brick : bricks)
		if (!brick.exists)
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height);
}

void Graphics::show() {
	setcolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(ball.x, ball.y, ball.radius);
	bar(barect.left, barect.top, barect.right, barect.bottom);
	for (const auto &brick : bricks)
		if (brick.exists) {
			setcolor(WHITE);
			setfillcolor(RED);
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height);
		}
	FlushBatchDraw();
	Sleep(3);
}

void Graphics::updateBallPosition() {
	ball.x += ball.vx;
	ball.y += ball.vy;
}