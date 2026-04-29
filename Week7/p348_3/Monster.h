#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Canvas.h"

#define DIM 40

class Monster {
    std::string name, icon;
    int x, y, nItem;
    int nEnergy; // (1) 에너지 속성 추가

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int map[DIM][DIM]) {
        if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
            nEnergy += 8; // (3) 아이템 먹으면 +8
        } else {
            nEnergy -= 1; // (3) 못 먹으면 -1
            if (nEnergy < 0) nEnergy = 0;
        }
    }

public:
    // (2) 멤버 초기화 리스트로 nEnergy를 100으로 초기화
    Monster(std::string n = "괴물", std::string i = "※", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}

    ~Monster() { std::cout << "\t" << name << icon << " 퇴장합니다." << std::endl; }

    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }

    void move(int map[DIM][DIM], int maxx, int maxy) {
        switch (rand() % 8) {
            case 0: y--; break;
            case 1: x++; y--; break;
            case 2: x++; break;
            case 3: x++; y++; break;
            case 4: y++; break;
            case 5: x--; y++; break;
            case 6: x--; break;
            case 7: x--; y--; break;
        }
        clip(maxx, maxy);
        eat(map);
    }

    // (4) 에너지 레벨 출력 수정
    void print() {
        std::cout << "\t" << name << icon << " : " << nItem << "  E:" << nEnergy << std::endl;
    }
};