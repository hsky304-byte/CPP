// MonsterWorldGame.cpp
#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <ctime>
#include <cstdio>

int main() {
    // 난수 생성기 초기화
    srand((unsigned int)time(NULL));
    
    int w = 16, h = 8;
    MonsterWorld game(w, h);

    // [기본 교재 구현 대상 객체 추가]
    game.add(new Zombie("허접좀비", "Z", rand() % w, rand() % h));
    game.add(new Vampire("뱀파이어", "V", rand() % w, rand() % h));
    game.add(new KGhost("처녀귀신", "G", rand() % w, rand() % h));
    game.add(new Jiangshi("가로강시", "H", rand() % w, rand() % h, true));
    game.add(new Jiangshi("세로강시", "Y", rand() % w, rand() % h, false));

    // =============================================================
    // 연습문제 (4): 추가된 클래스의 객체들을 생성하여 몬스터 월드에 추가
    // =============================================================
    
    // (1) 대각선으로만 움직이는 스몸비 추가
    game.add(new Smombi("길막스몸비", "S", rand() % w, rand() % h));

    // (2) 강시를 상속받고 주기적으로 가로/세로 방향을 바꾸는 수퍼강시 샹시 추가
    game.add(new Siangshi("질주샹시", "X", rand() % w, rand() % h, true));

    // (3) 나만의 독창적인 몬스터 (1~3칸 무작위 돌진 늑대인간) 추가
    game.add(new Werewolf("울버린늑대", "W", rand() % w, rand() % h));

    // 총 15턴 동안 진행, 각 턴 간격은 500ms(0.5초)로 설정해 시뮬레이션 시작
    game.play(15, 500);

    printf("-------게임 종료---------------------\n");
    return 0;
}