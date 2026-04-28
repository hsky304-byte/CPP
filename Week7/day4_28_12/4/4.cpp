#include <iostream>

class Complex {
public:
    double real, imag;
    // 멤버 함수: b를 참조로 받아 합산 후 새로운 객체 반환
    Complex add(Complex& b) {
        Complex temp;
        temp.real = this->real + b.real;
        temp.imag = this->imag + b.imag;
        return temp;
    }
};

int main() {
    Complex a = {1, 2}, b = {3, 4}, c;
    c = a.add(b);
    std::cout << "결과: " << c.real << " + " << c.imag << "i" << std::endl;
    return 0;
}