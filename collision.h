#ifndef COLLISION_H
#define COLLISION_H

#include "game.h"

namespace Collision {

	// 检查小球是否与挡板发生碰撞并更新状态
	bool checkBallBarCollision();
	bool checkBallBrickCollision();
	void checkBallBoundaryCollision();

} // namespace Collision

#endif // COLLISION_H