#include "utils.h"
#include <conio.h>

void Input::updateWithInput() {
	char input;
	if (kbhit()) { // 判断是否有输入
		input = getch();  // 根据用户的不同输入来移动，不必输入回车
		if (input == 'a' && barect.left > 0) {
			barect.x -= 15; // 位置左移
			GameLogic::updateBarBounds(); // 更新挡板边界
		}
		if (input == 'd' && barect.right < Game::Width) {
			barect.x += 15; // 位置右移
			GameLogic::updateBarBounds(); // 更新挡板边界
		}
	}
}