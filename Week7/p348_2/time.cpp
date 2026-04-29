#include <iostream>
using namespace std;

class MyTime {
    int hour, min, sec, mil;
public:
    // 기존 정수형 생성자 (문제 1번 내용)
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) 
        : hour(h), min(m), sec(s), mil(ms) {}

    // [문제 2] 실수형(double) 매개변수를 받는 생성자 추가
    MyTime(double duration) {
        hour = (int)(duration / 3600);           // 전체 초를 3600으로 나누면 '시'
        duration -= hour * 3600;
        
        min = (int)(duration / 60);             // 남은 초를 60으로 나누면 '분'
        duration -= min * 60;
        
        sec = (int)duration;                    // 정수 부분은 '초'
        mil = (int)((duration - sec) * 1000);   // 소수점 아래는 '밀리초'
        
        cout << "실수형 매개변수 생성자 호출 (변환 완료)" << endl;
    }

    void print() {
        printf("%02d:%02d:%02d:%03d\n", hour, min, sec, mil);
    }
};

int main() {
    // 3661.5초 = 1시간 1분 1초 500밀리초
    MyTime t3(3661.5); 
    t3.print();

    return 0;
}