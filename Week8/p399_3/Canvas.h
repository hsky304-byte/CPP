#pragma once
#include <iostream>
#include <string>
#include <vector>

class Canvas {
    int width, height;
    std::vector<std::vector<std::string>> board;

public:
    Canvas(int w = 40, int h = 20) : width(w), height(h) {
        board.assign(height, std::vector<std::string>(width, " "));
    }

    // 화면을 모두 빈칸으로 초기화
    void clear() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                board[i][j] = "  "; // 리눅스 터미널 간격을 위해 공백 2개
            }
        }
    }

    // 특정 위치(x, y)에 아이콘이나 문자 삽입
    void draw(int x, int y, std::string symbol) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            board[y][x] = symbol;
        }
    }

    // 현재 보드 상태를 터미널에 출력
    void print(std::string title) {
        std::cout << "\n\t" << title << "\n\t";
        for (int i = 0; i < width; i++) std::cout << "==";
        std::cout << "\n";

        for (int i = 0; i < height; i++) {
            std::cout << "\t|";
            for (int j = 0; j < width; j++) {
                std::cout << board[i][j];
            }
            std::cout << "|\n";
        }

        std::cout << "\t";
        for (int i = 0; i < width; i++) std::cout << "==";
        std::cout << "\n";
    }
};