#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// (1) 무작위 채우기
void randomMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2;
        }
    }
}

// (2) 화면 출력
void printMap(int map[5][5]) {
    printf("[ Checker Board ]\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("-----------------\n");
}

// (3) 가로, 세로, 대각선 체크
void checkMap(int map[5][5]) {
    int found = 0;

    // 가로 체크
    for (int i = 0; i < 5; i++) {
        if (map[i][0] == map[i][1] && map[i][1] == map[i][2] && 
            map[i][2] == map[i][3] && map[i][3] == map[i][4]) {
            printf("가로 %d행이 모두 %d입니다.\n", i + 1, map[i][0]);
            found = 1;
        }
    }

    // 세로 체크
    for (int j = 0; j < 5; j++) {
        if (map[0][j] == map[1][j] && map[1][j] == map[2][j] && 
            map[2][j] == map[3][j] && map[3][j] == map[4][j]) {
            printf("세로 %d열이 모두 %d입니다.\n", j + 1, map[0][j]);
            found = 1;
        }
    }

    // 대각선 체크 (좌상단 -> 우하단)
    if (map[0][0] == map[1][1] && map[1][1] == map[2][2] && 
        map[2][2] == map[3][3] && map[3][3] == map[4][4]) {
        printf("왼쪽 대각선이 모두 %d입니다.\n", map[0][0]);
        found = 1;
    }

    // 대각선 체크 (우상단 -> 좌하단)
    if (map[0][4] == map[1][3] && map[1][2] == map[2][2] && 
        map[2][2] == map[3][1] && map[3][1] == map[4][0]) {
        printf("오른쪽 대각선이 모두 %d입니다.\n", map[0][4]);
        found = 1;
    }

    if (!found) {
        printf("조건을 만족하는 라인이 없습니다.\n");
    }
}

int main() {
    srand(time(NULL));
    int map[5][5];

    printf("--- 3단계: 전체 기능 테스트 ---\n");
    randomMap(map);
    printMap(map);
    checkMap(map);

    return 0;
}