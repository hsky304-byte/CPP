#include "Minesweeper.h"

int main() {
    int total;
    printf("< Mine Sweeper >\n");
    printf("매설할 총 지뢰의 개수 입력 : ");
    scanf("%d", &total);
    getchar(); // 버퍼 비우기

    playMineSweeper(total);
    return 0;
}
