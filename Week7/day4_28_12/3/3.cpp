#include <iostream>

class Complex {
public:
    double real, imag;
    // 멤버 함수: 호출한 객체(this)의 데이터를 변경
    void add(Complex& a, Complex& b) {
        this->real = a.real + b.real;
        this->imag = a.imag + b.imag;
    }
};

int main() {
    Complex a = {1, 2}, b = {3, 4}, c;
    c.add(a, b);
    std::cout << "결과: " << c.real << " + " << c.imag << "i" << std::endl;
    return 0;
}