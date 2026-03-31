#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void randomMap(int map[5][5]);
void printMap(int map[5][5]);

int main()
{
    int map[5][5];

    srand(time(0));

    randomMap(map);
    printMap(map);

    return 0;
}

void randomMap(int map[5][5])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            map[i][j] = rand() % 2;
        }
    }
}

void printMap(int map[5][5])
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}