// MonsterWorld.h
#pragma once
#include "Monster.h"
#include <vector>
#include <unistd.h> 

class MonsterWorld {
private:
    int width, height;
    int** map;
    std::vector<Monster*> monsters;

public:
    MonsterWorld(int w, int h) : width(w), height(h) {
        map = new int*[height];
        for (int i = 0; i < height; ++i) {
            map[i] = new int[width];
            for (int j = 0; j < width; ++j) {
                // 15%의 확률로 먹을 아이템(값 1)을 생성
                map[i][j] = (rand() % 100 < 15) ? 1 : 0;
            }
        }
    }

    ~MonsterWorld() {
        for (auto m : monsters) {
            delete m; // 동적 할당된 자식 객체 소멸 (가상소멸자 작동)
        }
        for (int i = 0; i < height; ++i) {
            delete[] map[i];
        }
        delete[] map;
    }

    void add(Monster* m) {
        monsters.push_back(m);
    }

    void draw() {
        // 리눅스 터미널 화면을 깨끗이 비워 실시간 애니메이션처럼 보이게 함
        std::cout << "\033[H\033[J"; 
        
        // 상단 테두리 벽
        for (int i = 0; i < width + 2; ++i) std::cout << "■";
        std::cout << "\n";

        for (int i = 0; i < height; ++i) {
            std::cout << "■"; // 좌측 벽
            for (int j = 0; j < width; ++j) {
                bool monsterDrawn = false;
                for (auto m : monsters) {
                    if (m->getX() == j && m->getY() == i) {
                        std::cout << m->getIcon();
                        monsterDrawn = true;
                        break;
                    }
                }
                if (!monsterDrawn) {
                    if (map[i][j] > 0) std::cout << "·"; // 아이템 표시
                    else std::cout << "  ";             // 빈 공간
                }
            }
            std::cout << "■\n"; // 우측 벽
        }

        // 하단 테두리 벽
        for (int i = 0; i < width + 2; ++i) std::cout << "■";
        std::cout << "\n";
    }

    void play(int max_turns = 10, int delay_ms = 500) {
        for (int turn = 0; turn < max_turns; ++turn) {
            draw();
            std::cout << "[Turn " << turn + 1 << " / " << max_turns << "]\n";
            for (auto m : monsters) {
                m->move(map, width, height);
            }
            usleep(delay_ms * 1000); // 리눅스 환경에서 마이크로초 단위 딜레이 제어
        }
    }
};