#include "utils.h"
#include <conio.h>

void Input::updateWithInput() {
	char input;
	if (kbhit()) { // �ж��Ƿ�������
		input = getch();  // �����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == 'a' && barect.left > 0) {
			barect.x -= 15; // λ������
			GameLogic::updateBarBounds(); // ���µ���߽�
		}
		if (input == 'd' && barect.right < Game::Width) {
			barect.x += 15; // λ������
			GameLogic::updateBarBounds(); // ���µ���߽�
		}
	}
}