void add(Complex& a, Complex& b, Complex& c) {
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
}

// 사용 예시
Complex a(1, 2), b(3, 4), c;
add(a, b, c); // c에 결과가 저장됨