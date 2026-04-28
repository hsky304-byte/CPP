#include <cstdio>

struct MyTime 
{
    int h, m, s, ms;
};


void addTime(MyTime t1, MyTime t2, MyTime& t3) 
{
    int carry = 0;

    t3.ms = (t1.ms + t2.ms) % 1000;
    carry = (t1.ms + t2.ms) / 1000;

    t3.s = (t1.s + t2.s + carry) % 60;
    carry = (t1.s + t2.s + carry) / 60;

    t3.m = (t1.m + t2.m + carry) % 60;
    carry = (t1.m + t2.m + carry) / 60;

    t3.h = t1.h + t2.h + carry;
}

int main() 
{
    MyTime t1 = {1, 40, 30, 700};
    MyTime t2 = {0, 30, 40, 500};
    MyTime result; 

    
    addTime(t1, t2, result);

    printf("%02d:%02d:%02d:%03d\n", result.h, result.m, result.s, result.ms);

    return 0;
}
