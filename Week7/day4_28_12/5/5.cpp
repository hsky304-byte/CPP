#include <iostream>

class Complex {
public:
    double real, imag;
    // 연산자 오버로딩: c = a + b 형태 가능
    Complex operator+(Complex& b) {
        Complex temp;
        temp.real = this->real + b.real;
        temp.imag = this->imag + b.imag;
        return temp;
    }
};

int main() {
    Complex a = {1, 2}, b = {3, 4}, c;
    c = a + b; // a.operator+(b)와 동일
    std::cout << "결과: " << c.real << " + " << c.imag << "i" << std::endl;
    return 0;
}