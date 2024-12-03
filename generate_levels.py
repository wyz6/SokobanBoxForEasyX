# -*- coding: utf-8 -*-
import os
import random

def generate_levels(num_levels, level_info_path):
    if not os.path.exists(level_info_path):
        os.makedirs(level_info_path)

    for i in range(1, num_levels + 1):
        filename = os.path.join(level_info_path, f"level_{i}.txt")
        print(f"Generating level file: {filename}")  # �����־���
        with open(filename, 'w', encoding='utf-8') as file:
            num_bricks = 10  # ÿ���ؿ�����10��ש��
            for _ in range(num_bricks):
                x = random.randint(0, 800 - 100)  # ������Ϸ���Ϊ800
                y = random.randint(0, 600 - 50)   # ������Ϸ�߶�Ϊ600
                width = random.randint(50, 100)
                height = random.randint(20, 40)
                file.write(f"{x} {y} {width} {height}\n")

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print("Usage: python generate_levels.py <num_levels> <level_info_path>")
        sys.exit(1)
    
    num_levels = int(sys.argv[1])
    level_info_path = sys.argv[2]
    generate_levels(num_levels, level_info_path)