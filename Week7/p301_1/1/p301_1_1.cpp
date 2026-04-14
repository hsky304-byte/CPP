#include <iostream>
#include <iomanip> // setw, setfill 사용을 위해 필요

using namespace std;

class MyTime 
{
protected: 
    int hours, minutes, seconds, msecs;

public:
    
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0)
        : hours(h), minutes(m), seconds(s), msecs(ms) {}

    
    void print() {
        cout << setfill('0') << setw(2) << hours << ":"
             << setw(2) << minutes << ":"
             << setw(2) << seconds << ":"
             << setw(3) << msecs << endl;
    }
};

int main() 
{
    MyTime t1(1, 2, 34, 567);
    cout << "1단계 테스트 (출력): ";
    t1.print();
    return 0;
}