#ifndef UTILS_H
#define UTILS_H

// ��׼��ͷ�ļ�
#include <iostream>
#include <vector>
#include <string>
#include <cmath>        // ��ѧ����
#include <cstdlib>      // ���� exit() �� rand()
#include <ctime>        // ����ʱ����غ���
#include <limits>       // ������ֵ����
#include <algorithm>    // ���� std::clamp ���㷨
#include <fstream>      // �����ļ�����

// ��������ͷ�ļ�
#include <easyxgraphics.h>  // EasyX ͼ�ο�

// �Զ���ͷ�ļ�
#include "include/game.h"        // ��Ϸ��ص�ȫ�ֱ����ͳ���
#include "include/collision.h"   // ��ײ���ģ��
#include "include/graphics.h"    // ͼ�λ���ģ��
#include "include/input.h"       // �û����봦��ģ��
#include "include/game_logic.h"  // ��Ϸ�߼�ģ��
#include "include/level.h"       // �ؿ�ģ��
#include "include/level_generator.h"  // �����Ĺؿ�������ģ��

// �궨��
#define GAME_TITLE "��ש����Ϸ"
#define FRAME_RATE 60  // ÿ��֡��

#endif // UTILS_H