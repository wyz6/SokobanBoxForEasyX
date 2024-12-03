#ifndef LEVEL_H
#define LEVEL_H

#include "game.h"

namespace Level {

	void loadLevel(const std::string &filename);
	void saveLevel(const std::string &filename);

} // namespace Level

#endif // LEVEL_H