#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// (1) 5x5 배열에 0과 1을 임의로 채우는 함수
void randomMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2; // 0 또는 1 무작위 생성
        }
    }
}

int main() {
    srand(time(NULL)); // 실행할 때마다 다른 값이 나오도록 시드 설정
    int map[5][5];

    printf("--- 1단계: Random Map 생성 ---\n");
    randomMap(map);
    printf("배열 생성이 완료되었습니다.\n");

    return 0;
}