#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
    int rows, cols;
    int** data; // 2차원 배열을 위한 더블 포인터

public:
    // 생성자: 행(r)과 열(c)을 입력받아 메모리 동적 할당
    Matrix(int r = 0, int c = 0) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            // 초기값을 0으로 설정
            for (int j = 0; j < cols; j++) data[i][j] = 0;
        }
    }

    // 소멸자: 동적 할당된 메모리 해제
    ~Matrix() {
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;
    }

    // 특정 위치(r, c)의 데이터에 접근 (참조 반환으로 값 수정 가능)
    int& elem(int r, int c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return data[r][c];
        }
        // 예외 상황 시 안전을 위해 첫 번째 요소 반환 (실제 서비스에선 에러 처리가 필요함)
        return data[0][0];
    }

    // 데이터 배열의 포인터를 반환 (Monster::move 함수 등에서 사용)
    int** Data() { return data; }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

#endif