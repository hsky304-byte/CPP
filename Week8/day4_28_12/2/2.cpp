#include <iostream>

struct Complex {
    double real, imag;
};

// 일반 함수: 결과 객체를 생성하여 리턴
Complex add(Complex a, Complex b) {
    Complex temp;
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    return temp;
}

int main() {
    Complex a = {1, 2}, b = {3, 4}, c;
    c = add(a, b);
    std::cout << "결과: " << c.real << " + " << c.imag << "i" << std::endl;
    return 0;
}
