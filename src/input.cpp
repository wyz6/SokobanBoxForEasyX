#include "../include/utils.h"
#include <conio.h>

void updateWithInput() {
	char input;
	if (kbhit()) {
		input = getch();
		switch (input) {
			case 'a': // ���ͷ��
				if (barect.left > 0) {
					barect.x -= 30; // �ƶ���������
					updateBarBounds(); // ���µ���߽�
				}
				break;
			case 'd': // �Ҽ�ͷ��
				if (barect.right < Width) {
					barect.x += 30; // �ƶ���������
					updateBarBounds(); // ���µ���߽�
				}
				break;
		}
	}
}