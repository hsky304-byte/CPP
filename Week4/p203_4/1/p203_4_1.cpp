#include <iostream>
#include <cstdio>
#include <cstdlib>

int DIM = 4;
int map[5][5];

void init(int d) {
    DIM = d;
    for (int i = 0; i < DIM * DIM - 1; i++)
        map[i / DIM][i % DIM] = i + 1;
    map[DIM - 1][DIM - 1] = 0;
}

void display() {
    system("clear");
    printf("[%d x %d Puzzle]\n", DIM, DIM);
    for (int r = 0; r < DIM; r++) {
        for (int c = 0; c < DIM; c++) {
            if (map[r][c] > 0) printf("%3d", map[r][c]);
            else printf("   ");
        }
        printf("\n");
    }
}

int main() {
    int d;
    printf("퍼즐 크기 선택 (3, 4, 5): ");
    if(scanf("%d", &d) != 1) return 0;
    init(d);
    display();
    return 0;
}