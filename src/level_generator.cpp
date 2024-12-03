#include "../include/utils.h"

namespace LevelGenerator {

	void generateLevels(int numLevels, const std::string &levelInfoPath) {
		// 确保目录存在
		if (!std::filesystem::exists(levelInfoPath)) {
			std::filesystem::create_directories(levelInfoPath);
		}

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

			std::string filename = levelInfoPath + "level_" + std::to_string(i) + ".txt";
			std::cout << "Saving level to: " << filename << std::endl; // 日志输出

			std::ofstream file(filename);
			if (!file.is_open()) {
				std::cerr << "Failed to create level file: " << filename << std::endl;
				continue;
			}

			for (const auto &brick : bricks) {
				file << brick.x << " " << brick.y << " " << brick.width << " " << brick.height << std::endl;
			}

			file.close();
		}
	}

} // namespace LevelGenerator