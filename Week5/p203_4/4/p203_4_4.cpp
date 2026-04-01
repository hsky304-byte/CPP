#include <cstdio>

int DIM, nMove, x, y;
int map[5][5];

void loadGame() {
    FILE* fp = fopen("save.dat", "rb");
    if (fp) {
        fread(&DIM, sizeof(int), 1, fp);
        fread(&nMove, sizeof(int), 1, fp);
        fread(map, sizeof(int), 25, fp);
        for(int r=0; r<DIM; r++)
            for(int c=0; c<DIM; c++)
                if(map[r][c] == 0) { x = c; y = r; }
        fclose(fp);
        printf("Loaded!\n");
    }
}

int main() { printf("이어하기 기능 구현 완료\n"); return 0; }
