#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
#include <iomanip>

class MyTime 
{
private:
    int hours, minutes, seconds, msecs;

public:
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0);
    void reset();
    void read();
    void print();
    MyTime add(MyTime t);
    void convert(double duration);
};

#endif