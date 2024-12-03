#include "level_generator.h"
#include "level.h"
#include <random>
#include <vector>
#include <fstream>
#include <string>
#include <ctime>

namespace LevelGenerator {

	void generateLevels(int numLevels) {
		std::mt19937 rng(static_cast<unsigned>(time(nullptr)));
		std::uniform_int_distribution<int> xDist(0, Game::Width - 100);
		std::uniform_int_distribution<int> yDist(0, Game::High - 50);
		std::uniform_int_distribution<int> widthDist(50, 100);
		std::uniform_int_distribution<int> heightDist(20, 40);

		for (int i = 1; i <= numLevels; ++i) {
			std::vector<Game::Brick> bricks;
			int numBricks = 10; // 每个关卡包含10个砖块

			for (int j = 0; j < numBricks; ++j) {
				Game::Brick brick;
				brick.x = xDist(rng);
				brick.y = yDist(rng);
				brick.width = widthDist(rng);
				brick.height = heightDist(rng);
				brick.exists = true;
				bricks.push_back(brick);
			}

			std::string filename = "../level_info/level_" + std::to_string(i) + ".txt";
			Level::saveLevel(filename);
		}
	}

} // namespace LevelGenerator