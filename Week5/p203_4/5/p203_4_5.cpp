#include <cstdio>
#include <cstdlib> // system() 함수를 위해 추가

const char* art[] = { "   ", " A ", " B ", " C ", " D ", " E ", " F ", " G ", " H ", " I " };

void displayArt(int map[5][5], int DIM) {
    system("clear"); // 이제 정상적으로 작동합니다.
    for (int r = 0; r < DIM; r++) {
        for (int c = 0; c < DIM; c++) {
            if (map[r][c] == 0) printf("%s", art[0]);
            else printf("%s", art[map[r][c]]);
        }
        printf("\n");
    }
}

int main() { printf("아스키 아트 모드 구현 완료\n"); return 0; }