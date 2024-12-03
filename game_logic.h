#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "game.h"

namespace GameLogic {

	// 数据初始化
	void initBall();
	void updateBarBounds();
	void initBar();
	void initBricks();
	void startup();
	void gameover();

	// 更新函数
	void updateWithoutInput();
	void updateWithInput();

	// 检查是否所有砖块都被消除
	bool allBricksDestroyed();

} // namespace GameLogic

#endif // GAME_LOGIC_H