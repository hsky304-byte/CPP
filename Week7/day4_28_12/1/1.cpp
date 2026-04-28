#include <iostream>

struct Complex {
    double real, imag;
};

// 일반 함수: 세 번째 인자인 c를 참조로 받아 결과 저장
void add(Complex& a, Complex& b, Complex& c) {
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
}

int main() {
    Complex a = {1, 2}, b = {3, 4}, c;
    add(a, b, c);
    std::cout << "결과: " << c.real << " + " << c.imag << "i" << std::endl;
    return 0;
}