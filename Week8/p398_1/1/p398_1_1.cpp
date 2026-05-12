#include <iostream>

class Sample {
    char *name;
    static int count; // (1) 정적 변수 선언

public:
    Sample() { count++; }
    Sample(const char *name) { count++; }
    
    // (1) 정적 출력 함수 구현
    static void printCount() {
        std::cout << "현재 객체 개수: " << count << std::endl;
    }
};

int Sample::count = 0; // 정적 변수 초기화

int main() {
    Sample a;
    Sample b;
    Sample::printCount(); // 2 출력
    return 0;
}