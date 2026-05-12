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

    ~Sample() {
        if (name != nullptr) delete[] name;
        count--;
    }

    // (4) 복사 생성자 구현 (깊은 복사)
    Sample(const Sample& src) {
        if (src.name != nullptr) {
            this->name = new char[strlen(src.name) + 1];
            strcpy(this->name, src.name);
        } else {
            this->name = nullptr;
        }
        count++;
    }

    static void printCount() {
        std::cout << "현재 객체 개수: " << count << std::endl;
    }
    
    void printName() { std::cout << "Name: " << (name ? name : "None") << std::endl; }
};

int Sample::count = 0;

int main() {
    Sample a("Original");
    Sample b(a); // 복사 생성자 호출
    
    std::cout << "객체 a: "; a.printName();
    std::cout << "객체 b (복사본): "; b.printName();
    
    Sample::printCount(); // 2 출력
    return 0;
}