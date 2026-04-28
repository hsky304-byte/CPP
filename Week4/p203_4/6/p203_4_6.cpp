#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <termios.h>

using namespace std;

// 4.7절 구조체
struct PlayInfo {
    char name[200];
    int nMove;
    double tElapsed;
};

// 전역 변수
PlayInfo MVP[10];
int current_nMVP = 0;
int DIM = 4, map[5][5], startMap[5][5], x, y, nMove = 0;
vector<int> history;

int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

// 6번 핵심: 이진 모드 랭킹 저장/불러오기
void loadRanking(const char* fname) {
    FILE* fp = fopen(fname, "rb");
    if (!fp) return;
    fread(&current_nMVP, sizeof(int), 1, fp);
    fread(MVP, sizeof(PlayInfo), current_nMVP, fp);
    fclose(fp);
}

void storeRanking(const char* fname) {
    FILE* fp = fopen(fname, "wb");
    if (!fp) return;
    fwrite(&current_nMVP, sizeof(int), 1, fp);
    fwrite(MVP, sizeof(PlayInfo), current_nMVP, fp);
    fclose(fp);
}

void addRanking(int move, double time) {
    if (current_nMVP < 10 || move < MVP[current_nMVP-1].nMove) {
        PlayInfo p;
        printf("\nRanking In! Name: ");
        scanf("%s", p.name);
        p.nMove = move; p.tElapsed = time;

        int pos = (current_nMVP < 10) ? current_nMVP++ : 9;
        while (pos > 0 && MVP[pos-1].nMove > move) {
            MVP[pos] = MVP[pos-1];
            pos--;
        }
        MVP[pos] = p;
    }
}

int main() {
    loadRanking("rank.bin");
    printf("--- Linux 15 Puzzle System Loaded ---\n");
    // 여기에 게임 루프와 1~5번 기능을 결합하여 실행합니다.
    storeRanking("rank.bin");
    return 0;
}