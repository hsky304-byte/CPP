#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <termios.h>

int getch() { // 리눅스용 getch
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

int DIM = 4, x, y;
int map[5][5], startMap[5][5];
std::vector<int> history;

void move(int key) {
    int nx = x, ny = y;
    if (key == 'w') ny--; else if (key == 's') ny++;
    else if (key == 'a') nx--; else if (key == 'd') nx++;
    else return;

    if (nx >= 0 && nx < DIM && ny >= 0 && ny < DIM) {
        map[y][x] = map[ny][nx]; map[ny][nx] = 0;
        x = nx; y = ny;
        history.push_back(key);
    }
}

void replay() {
    memcpy(map, startMap, sizeof(map));
    for(int r=0; r<DIM; r++) for(int c=0; c<DIM; c++) if(map[r][c]==0){x=c; y=r;}
    for (int k : history) {
        system("clear");
        printf("Replaying...\n");
        move(k);
        // display logic... (생략)
        usleep(300000);
    }
}

int main() { printf("리플레이 로직 포함 완료\n"); return 0; }