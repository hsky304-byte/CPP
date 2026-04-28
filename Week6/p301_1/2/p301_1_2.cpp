#include <iostream>
#include <iomanip>

using namespace std;

class MyTime 
{
protected:
    int hours, minutes, seconds, msecs;

public:
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0)
        : hours(h), minutes(m), seconds(s), msecs(ms) {}

    void print() {
        cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":"
             << setw(2) << seconds << ":" << setw(3) << msecs << endl;
    }

    
    MyTime add(MyTime t) {
        MyTime res;
        res.msecs = msecs + t.msecs;
        int carry = res.msecs / 1000;
        res.msecs %= 1000;

        res.seconds = seconds + t.seconds + carry;
        carry = res.seconds / 60;
        res.seconds %= 60;

        res.minutes = minutes + t.minutes + carry;
        carry = res.minutes / 60;
        res.minutes %= 60;

        res.hours = hours + t.hours + carry;
        return res;
    }
};

int main() 
{
    MyTime t1(1, 50, 40, 600);
    MyTime t2(0, 20, 30, 700);
    MyTime t3 = t1.add(t2);
    
    cout << "2단계 테스트 (덧셈 결과): ";
    t3.print(); 
    return 0;
}

//전역 함수 addTime(MyTime t1, MyTime t2)는 두 개의 매개변수가 필요했습니다. 하지만 객체지향(C++)의 멤버 함수 t1.add(t2)는 이미 t1 객체 자신이 시간 데이터를 가지고 있기 때문에, 더할 대상인 t2 한 개만 매개변수로 받으면 됩니다.