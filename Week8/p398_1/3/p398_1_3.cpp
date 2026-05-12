#include <iostream>
#include <cstring>

class Sample {
    char *name;
    static int count;

public:
    Sample() { name = nullptr; count++; }
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        count++;
    }

    // (3) 소멸자 구현
    ~Sample() {
        if (name != nullptr) {
            delete[] name; // 동적 메모리 해제
        }
        count--; // 객체 소멸 시 카운트 감소
        std::cout << "객체 소멸됨. ";
        printCount();
    }

    static void printCount() {
        std::cout << "현재 객체 개수: " << count << std::endl;
    }
};

int Sample::count = 0;

int main() {
    {
        Sample a("First");
        Sample b("Second");
        Sample::printCount(); // 2 출력
    } // 여기서 a, b의 소멸자가 호출됨
    
    Sample::printCount(); // 0 출력
    return 0;
}