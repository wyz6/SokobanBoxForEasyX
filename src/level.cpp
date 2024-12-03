#include "../include/utils.h"

void loadLevel(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to open level file: " + filename << std::endl; // 打开文件失败提示
		return;
	}

	bricks.clear();
	std::string line;
	while (std::getline(file, line)) {
		Brick brick;
		sscanf(line.c_str(), "%d %d %d %d", &brick.x, &brick.y, &brick.width, &brick.height); // 读取砖块信息
		brick.exists = true; // 设置砖块存在
		bricks.push_back(brick); // 添加砖块到列表
	}
	file.close();
}

void saveLevel(const std::string &filename) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to create level file: " + filename << std::endl; // 创建文件失败提示
		return;
	}

	for (const auto &brick : bricks) {
		file << brick.x << " " << brick.y << " " << brick.width << " " << brick.height << "\n"; // 写入砖块信息
	}
	file.close();
}