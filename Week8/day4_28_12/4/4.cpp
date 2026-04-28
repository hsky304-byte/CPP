Complex Complex::add(Complex& b) {
    Complex result;
    result.real = this->real + b.real;
    result.imag = this->imag + b.imag;
    return result;
}

// 사용 예시
Complex a(1, 2), b(3, 4);
Complex c = a.add(b);