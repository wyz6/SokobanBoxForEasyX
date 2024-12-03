#pragma once

#include "game.h"

void initBall(); // 初始化小球
void updateBarBounds(); // 更新挡板边界
void initBar(); // 初始化挡板
void startup(); // 启动游戏
void gameover(); // 结束游戏
void updateWithoutInput(); // 更新游戏状态（无输入）
bool allBricksDestroyed(); // 检查所有砖块是否被摧毁