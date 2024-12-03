#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include <random>
#include <easyxgraphics.h>

#include "../include/game.h"
#include "../include/collision.h"
#include "../include/graphics.h"
#include "../include/input.h"
#include "../include/game_logic.h"
#include "../include/level.h"

#define GAME_TITLE "打砖块游戏" // 游戏标题
#define FRAME_RATE 60 // 帧率