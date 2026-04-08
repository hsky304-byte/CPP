#include <iostream>
#include <cstdio>

using namespace std;

// [핵심] 배열을 전역 변수로 가장 위에 선언합니다.
static int MineMapMask[40][80];
static int MineMapLabel[40][80];
static int nx, ny; // 입력받을 맵의 가로, 세로 크기

int main() {
    printf("1. 맵 크기 입력 (가로 세로, 최대 80 40): ");
    scanf("%d %d", &nx, &ny);

    // 최대 크기 초과 방지
    if (nx > 80) nx = 80;
    if (ny > 40) ny = 40;

    // 맵 초기화 (0으로 채움)
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            MineMapMask[y][x] = 0;  // 0: 가려진 상태(Hide)
            MineMapLabel[y][x] = 0; // 0: 빈 칸(Empty)
        }
    }

    printf("\n--> %d x %d 맵이 성공적으로 생성되었습니다.\n", nx, ny);
    return 0;
}