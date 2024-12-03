#pragma once

#include "game.h"

bool checkBallBarCollision();  // 检测小球与挡板的碰撞
bool checkBallBrickCollision(); // 检测小球与砖块的碰撞
void checkBallBoundaryCollision(); // 检测小球与边界线的碰撞
