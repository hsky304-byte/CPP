#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// (1) 여러 자리 덧셈 문제를 출제하는 함수
void playAdd() 
{
    // 100~999 사이의 세 자리 수 두 개 생성
    int a = rand() % 900 + 100; 
    int b = rand() % 900 + 100;
    int answer;

    cout << "[덧셈 문제] " << a << " + " << b << " = ? ";
    cin >> answer;

    // 사용자가 입력한 값과 실제 합을 비교
    if (answer == a + b) {
        cout << "정답입니다! 연산 천재시군요." << endl;
    } else {
        cout << "오답입니다. 정답은 " << a + b << "입니다." << endl;
    }
}