#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "game.h"

namespace GameLogic {

	void initBall();
	void updateBarBounds();
	void initBar();
	void startup();
	void gameover();
	void updateWithoutInput();
	bool allBricksDestroyed();

} // namespace GameLogic

#endif // GAME_LOGIC_H