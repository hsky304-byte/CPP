#include "MonsterWorld.h"
#include <ctime>

int main() {
    srand((unsigned int)time(NULL));
    int w = 16, h = 8;

    MonsterWorld game(w, h);

    // 몬스터 생성 및 추가
    Monster m1("몬스터", "※", rand() % w, rand() % h);
    Monster m2("도깨비", "§", rand() % w, rand() % h);
    Monster m3("별그대", "★", rand() % w, rand() % h);
    Monster m4("고스트", "♥", rand() % w, rand() % h);

    game.add(&m1);
    game.add(&m2);
    game.add(&m3);
    game.add(&m4);

    game.play(500, 100); // 500회 이동, 100ms 대기

    std::cout << "---------- 게임 종료 ----------" << std::endl;
    return 0;
}