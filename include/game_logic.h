#pragma once

#include "game.h"

void initBall(); // ��ʼ��С��
void updateBarBounds(); // ���µ���߽�
void initBar(); // ��ʼ������
void startup(); // ������Ϸ
void gameover(); // ������Ϸ
void updateWithoutInput(); // ������Ϸ״̬�������룩
bool allBricksDestroyed(); // �������ש���Ƿ񱻴ݻ�