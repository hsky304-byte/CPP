#include <iostream>
using namespace std;

void checkMap(int map[5][5]);

int main()
{
    int map[5][5] =
    {
        {1,1,1,1,1},
        {0,1,0,1,0},
        {0,0,1,0,0},
        {1,0,1,0,1},
        {1,0,1,0,1}
    };

    checkMap(map);

    return 0;
}

void checkMap(int map[5][5])
{
    int i,j;

    // 가로 검사
    for(i=0;i<5;i++)
    {
        int sum=0;

        for(j=0;j<5;j++)
        {
            sum += map[i][j];
        }

        if(sum==0) cout<<"가로 "<<i<<"줄 모두 0"<<endl;
        if(sum==5) cout<<"가로 "<<i<<"줄 모두 1"<<endl;
    }

    // 세로 검사
    for(j=0;j<5;j++)
    {
        int sum=0;

        for(i=0;i<5;i++)
        {
            sum += map[i][j];
        }

        if(sum==0) cout<<"세로 "<<j<<"줄 모두 0"<<endl;
        if(sum==5) cout<<"세로 "<<j<<"줄 모두 1"<<endl;
    }

    // 대각선 검사
    int sum1=0;
    int sum2=0;

    for(i=0;i<5;i++)
    {
        sum1 += map[i][i];
        sum2 += map[i][4-i];
    }

    if(sum1==0) cout<<"대각선 모두 0"<<endl;
    if(sum1==5) cout<<"대각선 모두 1"<<endl;

    if(sum2==0) cout<<"반대 대각선 모두 0"<<endl;
    if(sum2==5) cout<<"반대 대각선 모두 1"<<endl;
}
