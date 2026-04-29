#include <iostream>
using namespace std;

class MyTime {
    int hour, min, sec, mil;
public:
    // 생성자: 매개변수가 없으면 0으로 초기화 (디폴트 매개변수 사용)
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) 
        : hour(h), min(m), sec(s), mil(ms) // 멤버 초기화 리스트
    {
        cout << "멤버 초기화 리스트를 이용한 생성자 호출" << endl;
    }

    void print() {
        printf("%02d:%02d:%02d:%03d\n", hour, min, sec, mil);
    }
};

int main() {
    MyTime t1(10, 20, 30, 500); // 매개변수 전달
    MyTime t2;                  // 매개변수 없음 (모두 0으로 초기화)
    
    t1.print();
    t2.print();
    return 0;
}