#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

// 전역 변수 선언
static int MineMapMask[40][80];
static int MineMapLabel[40][80];
static int nx, ny, nBomb; // nBomb: 지뢰 개수 추가

int main() {
    printf("2. 맵 크기(가로 세로)와 지뢰 개수 입력 (예: 10 10 15): ");
    scanf("%d %d %d", &nx, &ny, &nBomb);

    if (nx > 80) nx = 80;
    if (ny > 40) ny = 40;

    // 맵 초기화
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            MineMapMask[y][x] = 0;
            MineMapLabel[y][x] = 0;
        }
    }

    // 지뢰(9) 무작위 매설
    srand((unsigned int)time(NULL));
    for (int i = 0; i < nBomb; i++) {
        int x, y;
        do {
            x = rand() % nx;
            y = rand() % ny;
        } while (MineMapLabel[y][x] == 9); // 이미 지뢰가 있으면 다시 뽑기
        MineMapLabel[y][x] = 9; // 9는 지뢰를 의미
    }

    printf("\n--> %d x %d 맵에 %d개의 지뢰가 매설되었습니다.\n", nx, ny, nBomb);
    return 0;
}