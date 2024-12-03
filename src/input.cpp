#include "../include/utils.h"
#include <conio.h>

void updateWithInput() {
	char input;
	if (kbhit()) {
		input = getch();
		switch (input) {
			case 'a': // 左箭头键
				if (barect.left > 0) {
					barect.x -= 30; // 移动挡板向左
					updateBarBounds(); // 更新挡板边界
				}
				break;
			case 'd': // 右箭头键
				if (barect.right < Width) {
					barect.x += 30; // 移动挡板向右
					updateBarBounds(); // 更新挡板边界
				}
				break;
		}
	}
}