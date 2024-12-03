#ifndef COLLISION_H
#define COLLISION_H

#include "game.h"

namespace Collision {

	bool checkBallBarCollision();
	bool checkBallBrickCollision();
	void checkBallBoundaryCollision();

} // namespace Collision

#endif // COLLISION_H