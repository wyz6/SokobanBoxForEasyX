#include "../include/utils.h"

void loadLevel(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to open level file: " + filename << std::endl; // ���ļ�ʧ����ʾ
		return;
	}

	bricks.clear();
	std::string line;
	while (std::getline(file, line)) {
		Brick brick;
		sscanf(line.c_str(), "%d %d %d %d", &brick.x, &brick.y, &brick.width, &brick.height); // ��ȡש����Ϣ
		brick.exists = true; // ����ש�����
		bricks.push_back(brick); // ���ש�鵽�б�
	}
	file.close();
}

void saveLevel(const std::string &filename) {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to create level file: " + filename << std::endl; // �����ļ�ʧ����ʾ
		return;
	}

	for (const auto &brick : bricks) {
		file << brick.x << " " << brick.y << " " << brick.width << " " << brick.height << "\n"; // д��ש����Ϣ
	}
	file.close();
}