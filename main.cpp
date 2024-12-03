#include "utils.h"

void Level::loadLevel(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to open level file: " + filename << std::endl;
		return;
	}

	bricks.clear();

	std::string line;
	while (std::getline(file, line)) {
		Game::Brick brick;
		sscanf(line.c_str(), "%d %d %d %d", &brick.x, &brick.y, &brick.width, &brick.height);
		brick.exists = true;
		bricks.push_back(brick);
	}

	file.close();
}

void Level::saveLevel(const std::string &filename) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to create level file: " + filename << std::endl;
		return;
	}

	for (const auto &brick : bricks) {
		file << brick.x << " " << brick.y << " " << brick.width << " " << brick.height << std::endl;
	}

	file.close();
}