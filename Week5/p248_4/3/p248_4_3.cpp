#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

static int MineMapMask[40][80];
static int MineMapLabel[40][80];
static int nx, ny, nBomb;

// 맵 출력 함수
void printMap() {
    system("clear"); // Linux용 터미널 지우기 (Windows면 "cls")
    
    // 1. 열 번호 출력 (상단)
    printf("   ");
    for (int x = 0; x < nx; x++) printf("%d", x % 10);
    printf("\n   ");
    for (int x = 0; x < nx; x++) printf("-");
    printf("\n");

    // 2. 행 번호 및 맵 데이터 출력 (좌측)
    for (int y = 0; y < ny; y++) {
        printf("%2d|", y);
        for (int x = 0; x < nx; x++) {
            // 이 단계에서는 지뢰가 잘 심어졌는지 보기 위해 전부 출력해 봅니다.
            if (MineMapLabel[y][x] == 9) printf("※"); // 지뢰
            else printf("ㅁ");                        // 빈 칸
        }
        printf("\n");
    }
}

int main() {
    printf("3. 맵 크기 및 지뢰 개수 입력: ");
    scanf("%d %d %d", &nx, &ny, &nBomb);

    if (nx > 80) nx = 80; if (ny > 40) ny = 40;

    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            MineMapMask[y][x] = 0;
            MineMapLabel[y][x] = 0;
        }
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < nBomb; i++) {
        int x, y;
        do { x = rand() % nx; y = rand() % ny; } while (MineMapLabel[y][x] == 9);
        MineMapLabel[y][x] = 9;
    }

    // 출력 함수 호출
    printMap();
    return 0;
}