#pragma once
#include "Monster.h"
#include <unistd.h> // 리눅스용 지연 함수(usleep)를 위해 필요
#include <cstdio>

#define MAXMONS 20

class MonsterWorld {
    int map[DIM][DIM];
    int xMax, yMax, nMon, nMove;
    Monster* mon[MAXMONS]; // 객체 포인터 배열로 관리
    Canvas canvas;

    int& Map(int x, int y) { return map[y][x]; }

    int countItems() {
        int nItems = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (map[y][x] > 0) nItems++;
        return nItems;
    }

public:
    MonsterWorld(int w, int h) : canvas(w, h), xMax(w), yMax(h), nMon(0), nMove(0) {
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                map[y][x] = 1;
    }

    void add(Monster* m) {
        if (nMon < MAXMONS) mon[nMon++] = m;
    }

    void print() {
        // 리눅스 터미널 화면 초기화 (ANSI 이스케이프 시퀀스)
        std::cout << "\033[2J\033[1;1H"; 

        canvas.clear();
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (map[y][x] > 0) canvas.draw(x, y, ".");
        
        for (int i = 0; i < nMon; i++) mon[i]->draw(canvas);

        canvas.print("[ Monster World (Linux Edition) ]");
        std::cout << " 전체 이동 횟수 = " << nMove << std::endl;
        std::cout << " 남은 아이템 수 = " << countItems() << std::endl;
        for (int i = 0; i < nMon; i++) mon[i]->print();
    }

    void play(int maxwalk, int wait) {
        print();
        std::cout << " 엔터를 누르면 시작합니다...";
        getchar();

        for (int i = 0; i < maxwalk; i++) {
            nMove++;
            for (int j = 0; j < nMon; j++) mon[j]->move(map, xMax, yMax);
            print();
            usleep(wait * 1000); // 밀리초 단위를 마이크로초로 변환
            if (countItems() == 0) break;
        }
    }
};