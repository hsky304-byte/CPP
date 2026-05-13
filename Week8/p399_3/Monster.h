#pragma once
#include <iostream>
#include <string>
#include "Canvas.h"

#define DIM 40

class Monster {
    std::string name, icon;
    int x, y, nItem;
    int nEnergy;                // (1) 에너지 속성 추가
    static int sMonCount;       // (4) 정적 멤버 변수 선언

public:
    Monster(std::string n = "괴물", std::string i = "※", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) { // (1) 100으로 초기화
        sMonCount++;            // (4) 생성 시 카운트 증가
    }

    ~Monster() { 
        sMonCount--;            // (4) 소멸 시 카운트 감소
    }

    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }

    void move(int map[DIM][DIM], int maxx, int maxy) {
        int dir = rand() % 8;
        switch (dir) {
            case 0: y--; break; case 1: y++; break;
            case 2: x--; break; case 3: x++; break;
            // 대각선 이동 등 추가 가능
        }
        
        // 화면 밖으로 나가지 않게 처리
        if (x < 0) x = 0; if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0; if (y >= maxy) y = maxy - 1;

        // 아이템 먹기 로직
        if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
            nEnergy += 8;       // (3) 아이템 먹으면 에너지 +8
        } else {
            nEnergy -= 1;       // (3) 이동 시 에너지 -1
        }
        if (nEnergy < 0) nEnergy = 0;
    }

    int getEnergy() { return nEnergy; } // (2) 에너지 반환 함수
    std::string getName() { return name; }

    // (4) 정적 멤버 함수: 현재 몬스터 수 출력
    static void printCount() {
        std::cout << " 현재 전체 몬스터의 수: [" << sMonCount << "]" << std::endl;
    }

    // (1), (5) 에너지 정보를 포함한 출력
    void print() {
        std::cout << icon << ":" << name << "(E:" << nEnergy << ")  ";
    }
};