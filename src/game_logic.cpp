#include "../include/utils.h"

Game::Ball ball;
Game::Bar barect;
std::vector<Game::Brick> bricks;

void GameLogic::initBall() {
	ball.x = Game::Width / 2;
	ball.y = Game::High / 2;
	ball.vx = 5;
	ball.vy = -5;
	ball.radius = 10;
}

void GameLogic::updateBarBounds() {
	barect.left = barect.x - barect.w / 2;
	barect.right = barect.x + barect.w / 2;
	barect.top = barect.y - barect.h / 2;
	barect.bottom = barect.y + barect.h / 2;
}

void GameLogic::initBar() {
	barect.h = Game::High / 20;
	barect.w = Game::Width / 4;
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
	Collision::checkBallBarCollision();
	Collision::checkBallBrickCollision();
	Collision::checkBallBoundaryCollision();
	Graphics::updateBallPosition();
}

bool GameLogic::allBricksDestroyed() {
	for (const auto &brick : bricks)
		if (brick.exists)
			return false;
	return true;
}