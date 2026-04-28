#include <iostream>
#include <iomanip>

using namespace std;

class MyTime 
{
private: 
    int hours, minutes, seconds, msecs;

public:
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0)
        : hours(h), minutes(m), seconds(s), msecs(ms) {}

    
    void reset() { hours = minutes = seconds = msecs = 0; }

    
    void read() 
    {
        cout << "시간 입력 (시 분 초 밀리초): ";
        cin >> hours >> minutes >> seconds >> msecs;
    }

    void print() 
    {
        cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":"
             << setw(2) << seconds << ":" << setw(3) << msecs << endl;
    }

    MyTime add(MyTime t) 
    {
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

    void convert(double duration) 
    {
        int total_s = (int)duration;
        msecs = (int)((duration - total_s) * 1000.0 + 0.5);
        hours = total_s / 3600;
        minutes = (total_s % 3600) / 60;
        seconds = total_s % 60;
    }
};

int main() 
{
    MyTime t1, t2, result;

    cout << "--- MyTime 클래스 최종 테스트 ---" << endl;
    
    // 1. 입력 
    t1.read();
    
    // 2. 변환 
    t2.convert(7200.123); // 2시간 0분 0초 123밀리초
    cout << "t2 (7200.123초 변환 결과): ";
    t2.print();

    // 3. 덧셈 
    result = t1.add(t2);
    cout << "t1 + t2 결과: ";
    result.print();

    // 4. 리셋 
    result.reset();
    cout << "결과 리셋 후: ";
    result.print();

    return 0;
}