#include "MyTime.h"
using namespace std;

MyTime::MyTime(int h, int m, int s, int ms) 
    : hours(h), minutes(m), seconds(s), msecs(ms) {}

void MyTime::reset() { hours = minutes = seconds = msecs = 0; }

void MyTime::read() 
{
    cout << "시간 입력 (시 분 초 밀리초): ";
    cin >> hours >> minutes >> seconds >> msecs;
}

void MyTime::print() 
{
    cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":"
         << setw(2) << seconds << ":" << setw(3) << msecs << endl;
}

MyTime MyTime::add(MyTime t) 
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

void MyTime::convert(double duration) 
{
    int total_s = (int)duration;
    msecs = (int)((duration - total_s) * 1000.0 + 0.5);
    hours = total_s / 3600;
    minutes = (total_s % 3600) / 60;
    seconds = total_s % 60;
}