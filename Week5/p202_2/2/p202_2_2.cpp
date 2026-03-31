#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2;
        }
    }
}

// (2) 체커보드를 보기 좋게 화면에 출력하는 함수
void printMap(int map[5][5]) {
    printf("현재 맵 상태:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int map[5][5];

    printf("--- 2단계: 생성 및 출력 ---\n");
    randomMap(map);
    printMap(map);

    return 0;
}
