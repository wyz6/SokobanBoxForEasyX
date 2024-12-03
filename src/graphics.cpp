#include "../include/utils.h"

void clean() {
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(ball.x, ball.y, ball.radius); // 绘制黑色背景覆盖小球
	bar(barect.left, barect.top, barect.right, barect.bottom); // 绘制黑色背景覆盖挡板
	for (const auto &brick : bricks)
		if (!brick.exists)
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height); // 绘制黑色背景覆盖已销毁的砖块
}

void show() {
	setcolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(ball.x, ball.y, ball.radius); // 绘制绿色的小球
	bar(barect.left, barect.top, barect.right, barect.bottom); // 绘制黄色的挡板
	for (const auto &brick : bricks)
		if (brick.exists) {
			setcolor(WHITE);
			setfillcolor(RED);
			fillrectangle(brick.x, brick.y, brick.x + brick.width, brick.y + brick.height); // 绘制红色的砖块
		}
	FlushBatchDraw(); // 刷新绘图
	Sleep(3); // 延迟一段时间
}

void updateBallPosition() {
	ball.x += ball.vx; // 更新小球x坐标
	ball.y += ball.vy; // 更新小球y坐标
}