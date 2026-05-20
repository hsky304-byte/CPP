// VariousMonsters.h
#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
    Zombie(std::string n = "허접좀비", std::string i = "§", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Zombie() { std::cout << " ~Zombie"; }
};

class Vampire : public Monster {
public:
    Vampire(std::string n = "뱀파이어", std::string i = "★", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Vampire() { std::cout << " ~Vampire"; }

    void move(int** map, int maxx, int maxy) override {
        int dir = rand() % 4;
        if (dir == 0) x--;
        else if (dir == 1) x++;
        else if (dir == 2) y--;
        else y++;
        clip(maxx, maxy);
        eat(map);
    }
};

class KGhost : public Monster {
public:
    KGhost(std::string n = "처녀귀신", std::string i = "♥", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~KGhost() { std::cout << " ~KGhost"; }

    void move(int** map, int maxx, int maxy) override {
        x = rand() % maxx;
        y = rand() % maxy;
        clip(maxx, maxy);
        eat(map);
    }
};

class Jiangshi : public Monster {
protected:
    bool bHori; // 가로 방향 이동 여부
public:
    Jiangshi(std::string n = "대륙강시", std::string i = "↔", int x = 0, int y = 0, bool bH = true)
        : Monster(n, i, x, y), bHori(bH) {}
    ~Jiangshi() { std::cout << " ~Jiangshi"; }

    void move(int** map, int maxx, int maxy) override {
        int dir = rand() % 2;
        int jump = rand() % 2 + 1;
        if (bHori) x += ((dir == 0) ? -jump : jump);
        else y += ((dir == 0) ? -jump : jump);
        clip(maxx, maxy);
        eat(map);
    }
};


// (1) 대각선으로만 움직일 수 있는 스몸비(Smombi) 클래스
class Smombi : public Monster {
public:
    Smombi(std::string n = "스몸비", std::string i = "◈", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Smombi() { std::cout << " ~Smombi"; }

    void move(int** map, int maxx, int maxy) override {
        // 대각선 4방향 무작위 선택 (좌상, 우상, 좌하, 우하)
        int dir = rand() % 4;
        if (dir == 0) { x--; y--; }      
        else if (dir == 1) { x++; y--; } 
        else if (dir == 2) { x--; y++; } 
        else { x++; y++; }               
        clip(maxx, maxy);
        eat(map);
    }
};

// (2) 기존 강시(Jiangshi)를 상속받아 일정 시간이 되면 방향을 바꾸는 수퍼 강시, 샹시(Siangshi) 클래스
class Siangshi : public Jiangshi {
private:
    int m_stepCount; // 움직인 횟수(시간 흐름 시뮬레이션)

public:
    Siangshi(std::string n = "수퍼강시 샹시", std::string i = "⇳", int x = 0, int y = 0, bool bH = true)
        : Jiangshi(n, i, x, y, bH), m_stepCount(0) {}
    ~Siangshi() { std::cout << " ~Siangshi"; }

    void move(int** map, int maxx, int maxy) override {
        // 부모 클래스(Jiangshi)의 기본 이동 방식을 그대로 재사용하여 호출
        Jiangshi::move(map, maxx, maxy);
        
        m_stepCount++;
        // 3번 움직일 때마다 이동 방향(가로 <-> 세로)을 반전시킴
        if (m_stepCount % 3 == 0) {
            bHori = !bHori; 
            std::cout << "\n[알림] " << name << "가 방향을 바꿨습니다! 현재 상태: " 
                      << (bHori ? "가로 이동" : "세로 이동") << "\n";
        }
    }
};

// (3) 나만의 몬스터 클래스 구현: 늑대인간(Werewolf) 클래스
// 뱀파이어처럼 사방으로 이동하지만, 힘이 강해 한 번에 1~3칸씩 무작위로 돌진합니다.
class Werewolf : public Monster {
public:
    Werewolf(std::string n = "늑대인간", std::string i = "W", int x = 0, int y = 0)
        : Monster(n, i, x, y) {}
    ~Werewolf() { std::cout << " ~Werewolf"; }

    void move(int** map, int maxx, int maxy) override {
        int dir = rand() % 4;
        int speed = rand() % 3 + 1; // 1~3칸 무작위 돌진 거량
        if (dir == 0) x -= speed;
        else if (dir == 1) x += speed;
        else if (dir == 2) y -= speed;
        else y += speed;
        clip(maxx, maxy);
        eat(map);
    }
};