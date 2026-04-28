#include <iostream>
#include <ctime>    // time() 함수 사용을 위해
#include <cstdlib>  // rand(), srand() 함수 사용을 위해

using namespace std;

// (1) 여러 자리의 덧셈 문제를 출제하는 함수
void playAdd() 
{
    // 100~999 사이의 세 자리 수 무작위 생성 (문제 예시의 3~9자리는 너무 커서 세 자리로 조정)
    int a = rand() % 900 + 100; 
    int b = rand() % 900 + 100;
    int answer;

    cout << a << " + " << b << " = ? ";
    cin >> answer;

    if (answer == a + b) {
        cout << "정답입니다!" << endl;
    } else {
        cout << "틀렸습니다. 정답은 " << a + b << "입니다." << endl;
    }
}

// (2) 두 자리 수 곱셈 문제를 출제하는 함수
void playMul() 
{
    // 10~99 사이의 두 자리 수 무작위 생성
    int a = rand() % 90 + 10;
    int b = rand() % 90 + 10;
    int answer;

    cout << a << " * " << b << " = ? ";
    cin >> answer;

    if (answer == a * b) {
        cout << "정답입니다!" << endl;
    } else {
        cout << "틀렸습니다. 정답은 " << a * b << "입니다." << endl;
    }
}