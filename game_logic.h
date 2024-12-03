#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "game.h"

namespace GameLogic {

	// ���ݳ�ʼ��
	void initBall();
	void updateBarBounds();
	void initBar();
	void initBricks();
	void startup();
	void gameover();

	// ���º���
	void updateWithoutInput();
	void updateWithInput();

	// ����Ƿ�����ש�鶼������
	bool allBricksDestroyed();

} // namespace GameLogic

#endif // GAME_LOGIC_H