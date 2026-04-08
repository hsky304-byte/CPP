#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

static int MineMapMask[40][80];  // 0: 숨김(ㅁ), 1: 열림(숫자), 2: 깃발(p)
static int MineMapLabel[40][80]; // 0~8: 주변 지뢰 수, 9: 지뢰
static int nx, ny, nBomb;

// 지뢰 맵 출력
void printMap() {
    system("clear");
    printf("   ");
    for (int x = 0; x < nx; x++) printf("%d", x % 10);
    printf("\n   ");
    for (int x = 0; x < nx; x++) printf("-");
    printf("\n");

    for (int y = 0; y < ny; y++) {
        printf("%2d|", y);
        for (int x = 0; x < nx; x++) {
            if (MineMapMask[y][x] == 0) printf("ㅁ");
            else if (MineMapMask[y][x] == 2) printf("🚩"); // 깃발 표시
            else { // 열린 상태 (Mask == 1)
                if (MineMapLabel[y][x] == 9) printf("※");
                else if (MineMapLabel[y][x] == 0) printf("  "); // 0이면 빈칸
                else printf("%d ", MineMapLabel[y][x]);
            }
        }
        printf("\n");
    }
}

// 빈 칸을 열었을 때 주변을 연쇄적으로 여는 재귀 함수
void dig(int x, int y) {
    if (x < 0 || x >= nx || y < 0 || y >= ny) return; // 맵 밖이면 무시
    if (MineMapMask[y][x] != 0) return; // 이미 열렸거나 깃발이면 무시

    MineMapMask[y][x] = 1; // 연다
    
    // 주변 지뢰가 0개인 안전지대라면 주변 8칸도 자동으로 연다
    if (MineMapLabel[y][x] == 0) {
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                dig(x + dx, y + dy);
            }
        }
    }
}

// 게임 종료 검사 (-1: 지뢰 밟음, 1: 승리, 0: 진행 중)
int checkDone() {
    int hiddenCount = 0;
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (MineMapMask[y][x] == 1 && MineMapLabel[y][x] == 9) return -1; // 지뢰 터짐
            if (MineMapMask[y][x] != 1) hiddenCount++;
        }
    }
    return (hiddenCount == nBomb) ? 1 : 0; // 안 열린 칸과 지뢰수가 같으면 승리
}

int main() {
    printf("가로 세로 지뢰개수 입력 (예: 15 10 20): ");
    scanf("%d %d %d", &nx, &ny, &nBomb);
    while (getchar() != '\n'); // 입력 버퍼 비우기 (매우 중요)

    if (nx > 80) nx = 80; if (ny > 40) ny = 40;

    // 1. 초기화 및 지뢰 매설
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

    // 2. 주변 지뢰 개수 계산 (0~8)
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (MineMapLabel[y][x] == 9) continue;
            int count = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int cx = x + dx, cy = y + dy;
                    if (cx >= 0 && cx < nx && cy >= 0 && cy < ny) {
                        if (MineMapLabel[cy][cx] == 9) count++;
                    }
                }
            }
            MineMapLabel[y][x] = count;
        }
    }

    // 3. 게임 메인 루프 (사용자 입력)
    int status = 0;
    char input[100];
    
    while (status == 0) {
        printMap();
        printf("\n명령어 입력 (파내기: x y, 깃발: p x y) -> ");
        
        // 공백 포함 한 줄 통째로 읽기
        if (fgets(input, sizeof(input), stdin) == NULL) break;

        int x, y;
        // 첫 글자가 p 이면 깃발 꽂기
        if (input[0] == 'p' || input[0] == 'P') {
            if (sscanf(input + 1, "%d %d", &x, &y) == 2) {
                if (x >= 0 && x < nx && y >= 0 && y < ny) {
                    // 깃발이 꽂혀있으면 해제, 아니면 꽂기
                    MineMapMask[y][x] = (MineMapMask[y][x] == 2) ? 0 : 2;
                }
            }
        } 
        // 아니면 파내기
        else {
            if (sscanf(input, "%d %d", &x, &y) == 2) {
                dig(x, y);
            }
        }
        
        status = checkDone();
    }

    // 결과 출력
    printMap();
    if (status == -1) printf("\n펑! 지뢰를 밟았습니다. GAME OVER\n");
    else if (status == 1) printf("\n축하합니다! 모든 지뢰를 찾았습니다.\n");

    return 0;
}