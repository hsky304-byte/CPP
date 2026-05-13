#include "MonsterWorld1d.h"
#include <ctime>

// (4) 리눅스 환경 static 변수 초기화 (필수)
int Monster::sMonCount = 0;

int main() {
    srand((unsigned int)time(NULL));
    int w = 16, h = 8;
    MonsterWorld game(w, h);

    game.add(new Monster("몬스터", "※", rand() % w, rand() % h));
    game.add(new Monster("도깨비", "§", rand() % w, rand() % h));
    game.add(new Monster("별그대", "★", rand() % w, rand() % h));
    game.add(new Monster("고스트", "♥", rand() % w, rand() % h));

    game.play(500, 100);

    cout << "---------- 게임 종료 ----------" << endl;
    return 0;
}