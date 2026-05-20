// Monster.h
#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

class Monster {
protected:
    std::string name;
    std::string icon;
    int x, y;

public:
    Monster(std::string n, std::string i, int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py) {}
    
    virtual ~Monster() {
        std::cout << " ~Monster() of " << name << "\n";
    }

    // 자식 클래스들이 고유의 이동 방식을 구현할 수 있도록 가상 함수 선언
    virtual void move(int** map, int maxx, int maxy) {}

    // 화면 밖으로 나가지 못하게 제한
    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    // 아이템 섭취 처리 함수
    void eat(int** map) {
        if (map != nullptr && map[y][x] > 0) {
            std::cout << name << "가 아이템을 먹었습니다!\n";
            map[y][x] = 0; // 아이템 제거
        }
    }

    // Getter 함수들
    std::string getName() const { return name; }
    std::string getIcon() const { return icon; }
    int getX() const { return x; }
    int getY() const { return y; }
};