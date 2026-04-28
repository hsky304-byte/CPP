void Complex::add(Complex& a, Complex& b) {
    this->real = a.real + b.real;
    this->imag = a.imag + b.imag;
}

// 사용 예시
Complex a(1, 2), b(3, 4), c;
c.add(a, b); // c의 내부 값이 변경됨