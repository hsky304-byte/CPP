#include "Minesweeper.h"

enum LabelType { Empty = 0, Bomb = 9 };
enum MaskType { Hide = 0, Open = 1, Flag = 2 };

static int MineMapMask[40][80];   // 문제 조건: 최대 40x80
static int MineMapLabel[40][80];
static int nx, ny;               // 사용자 입력 맵 크기
static int nBomb;

inline int& mask(int x, int y) { return MineMapMask[y][x]; }
inline int& label(int x, int y) { return MineMapLabel[y][x]; }
inline bool isValid(int x, int y) { return (x >= 0 && x < nx && y >= 0 && y < ny); }
inline bool isBomb(int x, int y) { return isValid(x, y) && label(x, y) == Bomb; }
inline bool isEmpty(int x, int y) { return isValid(x, y) && label(x, y) == Empty; }

static void dig(int x, int y) {
    if (isValid(x, y) && mask(x, y) != Open) {
        mask(x, y) = Open;
        if (label(x, y) == 0) {
            for (int i = -1; i <= 1; i++)
                for (int j = -1; j <= 1; j++)
                    if (i != 0 || j != 0) dig(x + i, y + j);
        }
    }
}

static void mark(int x, int y) {
    if (isValid(x, y)) {
        if (mask(x, y) == Hide) mask(x, y) = Flag;
        else if (mask(x, y) == Flag) mask(x, y) = Hide; // 깃발 해제 기능 추가
    }
}

static void print() {
    system("clear"); // Linux용 화면 지우기
    printf(" 발견: ??  전체 지뢰: %d\n", nBomb);

    // 열 번호 출력 (십의 자리와 일의 자리 구분 시 가독성 증대)
    printf("    ");
    for (int x = 0; x < nx; x++) printf("%d", x % 10);
    printf("\n    ");
    for (int x = 0; x < nx; x++) printf("-");
    printf("\n");

    for (int y = 0; y < ny; y++) {
        printf("%2d |", y); // 행 번호 출력
        for (int x = 0; x < nx; x++) {
            if (mask(x, y) == Hide) printf("ㅁ");
            else if (mask(x, y) == Flag) printf("🚩");
            else {
                if (isBomb(x, y)) printf("※");
                else if (label(x, y) == 0) printf("  ");
                else printf("%d ", label(x, y));
            }
        }
        printf("\n");
    }
}

static int countNbrBombs(int x, int y) {
    int count = 0;
    for (int yy = y - 1; yy <= y + 1; yy++)
        for (int xx = x - 1; xx <= x + 1; xx++)
            if (isBomb(xx, yy)) count++;
    return count;
}

static void init(int total, int w, int h) {
    nx = w; ny = h; nBomb = total;
    srand((unsigned int)time(NULL));
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            mask(x, y) = Hide;
            label(x, y) = 0;
        }
    }
    for (int i = 0; i < nBomb; i++) {
        int x, y;
        do { x = rand() % nx; y = rand() % ny; } while (label(x, y) == Bomb);
        label(x, y) = Bomb;
    }
    for (int y = 0; y < ny; y++)
        for (int x = 0; x < nx; x++)
            if (label(x, y) == Empty) label(x, y) = countNbrBombs(x, y);
}

// 문제 (4)번: 입력 방식 수정 (p 20 10 또는 20 10)
static bool getPos(int& x, int& y) {
    char input[100];
    printf("\n입력 (예: 20 10 또는 p 20 10) -> ");
    fgets(input, sizeof(input), stdin);

    if (input[0] == 'p' || input[0] == 'P') {
        sscanf(input + 1, "%d %d", &x, &y);
        return true; // 깃발 꽂기 모드
    } else {
        sscanf(input, "%d %d", &x, &y);
        return false; // 파내기 모드
    }
}

static int checkDone() {
    int count = 0;
    for (int y = 0; y < ny; y++) {
        for (int x = 0; x < nx; x++) {
            if (mask(x, y) != Open) count++;
            if (mask(x, y) == Open && isBomb(x, y)) return -1;
        }
    }
    return (count == nBomb) ? 1 : 0;
}

void playMineSweeper(int total) {
    int x, y, w, h;
    printf("맵 크기 입력 (가로 세로): ");
    scanf("%d %d", &w, &h);
    getchar(); // 버퍼 비우기

    if (w > 80) w = 80; if (h > 40) h = 40;

    init(total, w, h);
    int status = 0;
    do {
        print();
        bool isFlag = getPos(x, y);
        if (isFlag) mark(x, y);
        else dig(x, y);
        status = checkDone();
    } while (status == 0);

    print();
    if (status < 0) printf("\n실패: 지뢰 폭발!!!\n");
    else printf("\n성공: 탐색 성공!!!\n");
}
