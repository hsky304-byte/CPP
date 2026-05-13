#ifndef MONSTER_WORLD_H
#define MONSTER_WORLD_H

#include <vector>
#include <unistd.h>
#include "Monster.h"
#include "Matrix.h" // Matrix 파일이 프로젝트 폴더에 있어야 합니다.

using namespace std;

#define MAXMONS 8

class MonsterWorld {
    Matrix world;
    int xMax, yMax, nMon, nMove;
    Monster* pMon[MAXMONS];
    Canvas canvas;

public:
    MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h), nMon(0), nMove(0) {
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                world.elem(y, x) = (rand() % 10 == 0) ? 1 : 0;
    }

    ~MonsterWorld() {
        for (int i = 0; i < nMon; i++) delete pMon[i];
    }

    void add(Monster* m) {
        if (nMon < MAXMONS) pMon[nMon++] = m;
    }

    // (3) 에너지가 0인 몬스터 제거 (Hint 적용)
    void checkStarvation() {
        for (int i = 0; i < nMon; ) {
            if (pMon[i]->getEnergy() <= 0) {
                cout << "\n >> " << pMon[i]->getName() << " 몬스터가 굶어 죽었습니다." << endl;
                delete pMon[i];
                // 마지막 항목을 현재 위치로 복사하고 개수 감소
                if (i < nMon - 1) pMon[i] = pMon[nMon - 1];
                nMon--;
            } else {
                i++;
            }
        }
    }

    void print() {
        system("clear"); // 리눅스 화면 초기화
        canvas.clear();
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (world.elem(y, x) > 0) canvas.draw(x, y, ".");
        
        for (int i = 0; i < nMon; i++) pMon[i]->draw(canvas);
        canvas.print("[ Monster World (Dynamic) ]");

        cout << " 전체 이동 횟수 = " << nMove << endl;
        for (int i = 0; i < nMon; i++) pMon[i]->print(); // 에너지 출력
        cout << endl;
        Monster::printCount(); // (4) 정적 함수 호출
    }

    void play(int maxwalk, int wait_ms) {
        print();
        for (nMove = 0; nMove < maxwalk; nMove++) {
            for (int i = 0; i < nMon; i++) pMon[i]->move(NULL, xMax, yMax); // 실습을 위해 맵 인자 조정 필요
            checkStarvation(); // (3) 매 턴마다 아사 체크
            print();
            usleep(wait_ms * 1000);
            if (nMon <= 0) break;
        }
    }
};
#endif