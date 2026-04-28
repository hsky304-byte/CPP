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
        msecs = (int)((duration - total_s) * 1000.0 + 0.5); // 반올림
        hours = total_s / 3600;
        minutes = (total_s % 3600) / 60;
        seconds = total_s % 60;
    }
};

int main() 
{
    MyTime t1;
    t1.convert(3661.567); 
    cout << "3단계 테스트 (3661.567초 변환): ";
    t1.print();
    return 0;
}