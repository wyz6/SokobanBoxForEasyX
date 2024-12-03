# -*- coding: utf-8 -*-
import os
import random

def generate_levels(num_levels, level_info_path):
    if not os.path.exists(level_info_path):
        os.makedirs(level_info_path) # 创建目录如果不存在

    for i in range(1, num_levels + 1):
        filename = os.path.join(level_info_path, f"level_{i}.txt")
        with open(filename, 'w', encoding='utf-8') as file:
            num_bricks = 10
            for _ in range(num_bricks):
                x = random.randint(0, 640 - 100)
                y = random.randint(0, 480 - 50)
                width = random.randint(50, 100)
                height = random.randint(20, 40)
                file.write(f"{x} {y} {width} {height}\n") # 写入砖块信息

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print("Usage: python generate_levels.py <num_levels> <level_info_path>") # 使用说明
        sys.exit(1)
    
    num_levels = int(sys.argv[1])
    level_info_path = sys.argv[2]
    generate_levels(num_levels, level_info_path)