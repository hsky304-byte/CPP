#include "MyTime.h"
#include <iostream>

int main() 
{
    MyTime t1, t2;
    
    std::cout << "[t1 입력]" << std::endl;
    t1.read();
    
    std::cout << "[t2 5000.123초 변환]" << std::endl;
    t2.convert(5000.123);
    
    MyTime result = t1.add(t2);
    std::cout << "최종 합계: ";
    result.print();
    
    return 0;
}