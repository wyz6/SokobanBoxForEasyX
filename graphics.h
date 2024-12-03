#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "game.h"

namespace Graphics {

	// 消除画面
	void clean();
	void show();

	// 更新小球位置
	void updateBallPosition();

} // namespace Graphics

#endif // GRAPHICS_H