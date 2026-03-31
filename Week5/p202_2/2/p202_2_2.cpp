#include <iostream>
using namespace std;

void printMap(int map[5][5]);

int main()
{
    int map[5][5] =
    {
        {1,0,1,0,1},
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,1,0},
        {1,0,1,0,1}
    };

    printMap(map);

    return 0;
}

void printMap(int map[5][5])
{
    cout << "   0 1 2 3 4" << endl;   // 제목(열 번호)

    for(int i=0;i<5;i++)
    {
        cout << i << "  ";          // 행 번호 출력

        for(int j=0;j<5;j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
