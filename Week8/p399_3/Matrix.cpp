#include "Matrix.h"

// 만약 Matrix.h에서 선언만 하고 구현을 분리한다면 아래와 같이 작성합니다.
/*
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++) data[i][j] = 0;
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) delete[] data[i];
    delete[] data;
}

int& Matrix::elem(int r, int c) {
    return data[r][c];
}
*/