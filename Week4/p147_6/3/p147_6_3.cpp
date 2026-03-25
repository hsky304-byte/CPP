#include <iostream>
#include <ctime>    // time() 함수 사용을 위해
#include <cstdlib>  // rand(), srand() 함수 사용을 위해

using namespace std;

// (1) 여러 자리의 덧셈 문제를 출제하는 함수
void playAdd() {
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
void playMul() {
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

// 기존 구구단 함수 (참고용)
void playGuguOnce() {
    int a = rand() % 9 + 1; // 1~9
    int b = rand() % 9 + 1;
    int answer;

    cout << a << " * " << b << " = ? ";
    cin >> answer;

    if (answer == a * b) {
        cout << "정답입니다!" << endl;
    } else {
        cout << "틀렸습니다. 정답은 " << a * b << "입니다." << endl;
    }
}

int main() {
    // 랜덤 시드 초기화 (매번 다른 문제가 나오게 함)
    srand((unsigned int)time(NULL));

    int choice;

    while (true) {
        // (3) 프로그램 시작 시 메뉴 선택 인터페이스
        cout << "\n--- 게임 메뉴 ---" << endl;
        cout << "1: 구구단" << endl;
        cout << "2: 두 자리 수 곱셈" << endl;
        cout << "3: 세 자리 수 덧셈" << endl;
        cout << "0: 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                playGuguOnce();
                break;
            case 2:
                playMul();
                break;
            case 3:
                playAdd();
                break;
            default:
                cout << "잘못된 선택입니다. 다시 입력하세요." << endl;
        }
    }

    cout << "게임을 종료합니다." << endl;
    return 0;
}