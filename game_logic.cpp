#include "utils.h"

// 全局变量定义
Game::Ball ball;
Game::Bar barect;
std::vector<Game::Brick> bricks;

// 数据初始化
void GameLogic::initBall() {
	ball.x = Game::Width / 2;
	ball.y = Game::High / 2;
	ball.vx = 5;  // 调整初始水平速度
	ball.vy = -5; // 调整初始垂直速度
	ball.radius = 10; // 小球半径
}

void GameLogic::updateBarBounds() {
	barect.left = barect.x - barect.w / 2;
	barect.right = barect.x + barect.w / 2;
	barect.top = barect.y - barect.h / 2;
	barect.bottom = barect.y + barect.h / 2;
}

void GameLogic::initBar() {
	barect.h = Game::High / 20;
	barect.w = Game::Width / 4; // 挡板宽度
	barect.x = Game::Width / 2;
	barect.y = Game::High - barect.h / 2;

	updateBarBounds();
}

void GameLogic::startup() {
	initBall();
	initBar();

	initgraph(Game::Width, Game::High);
	BeginBatchDraw();
}

void GameLogic::gameover() {
	EndBatchDraw();
	closegraph();
}

void GameLogic::updateWithoutInput() {
	Collision::checkBallBarCollision();          // 检查小球与挡板的碰撞
	Collision::checkBallBrickCollision();        // 检查小球与砖块的碰撞
	Collision::checkBallBoundaryCollision();     // 检查小球与屏幕边界的碰撞
	Graphics::updateBallPosition();              // 更新小球的位置
}

bool GameLogic::allBricksDestroyed() {
	for (const auto &brick : bricks) {
		if (brick.exists) {
			return false;
		}
	}
	return true;
}