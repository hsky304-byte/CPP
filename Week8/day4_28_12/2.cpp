Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// 사용 예시
Complex a(1, 2), b(3, 4);
Complex c = add(a, b);