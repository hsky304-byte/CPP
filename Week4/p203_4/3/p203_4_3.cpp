#include <cstdio>

int DIM, nMove;
int map[5][5];

void saveGame() {
    FILE* fp = fopen("save.dat", "wb");
    if (fp) {
        fwrite(&DIM, sizeof(int), 1, fp);
        fwrite(&nMove, sizeof(int), 1, fp);
        fwrite(map, sizeof(int), 25, fp);
        fclose(fp);
        printf("Saved!\n");
    }
}

int main() { printf("저장 기능 구현 완료\n"); return 0; }