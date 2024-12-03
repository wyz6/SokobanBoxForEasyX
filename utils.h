#ifndef UTILS_H
#define UTILS_H

// 标准库头文件
#include <iostream>
#include <vector>
#include <string>
#include <cmath>        // 数学函数
#include <cstdlib>      // 用于 exit() 和 rand()
#include <ctime>        // 用于时间相关函数
#include <limits>       // 用于数值极限
#include <algorithm>    // 用于 std::clamp 等算法
#include <fstream>      // 用于文件操作

// 第三方库头文件
#include <easyxgraphics.h>  // EasyX 图形库

// 自定义头文件
#include "game.h"        // 游戏相关的全局变量和常量
#include "collision.h"   // 碰撞检测模块
#include "graphics.h"    // 图形绘制模块
#include "input.h"       // 用户输入处理模块
#include "game_logic.h"  // 游戏逻辑模块
#include "level.h"       // 关卡模块
#include "level_generator.h"  // 新增的关卡生成器模块

// 宏定义
#define GAME_TITLE "打砖块游戏"
#define FRAME_RATE 60  // 每秒帧数

#endif // UTILS_H