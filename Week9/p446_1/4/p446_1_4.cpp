#include <iostream>

class Point {
// [4번 문제 요구사항] protected 키워드를 private으로 변경
private:
    int x, y; 

public:
    Point(int xx, int yy) : x(xx), y(yy) { }
    void draw() {
        std::cout << x << "," << y << "에 점을 그려라.\n";
    }
};

class Rectangle : public Point {
private:
    int width;
    int height;
public:
    Rectangle(int xx, int yy, int w, int h) : Point(xx, yy), width(w), height(h) { }

    // (3)번에서 구현했던 draw() 함수 재정의 코드
    void draw() {
        // [컴파일 에러 발생 위치!]
        // x와 y는 부모인 Point의 private 멤버이므로, 
        // 자식 클래스인 Rectangle 내부라 할지라도 직접 접근할 수 없습니다.
        std::cout << x << "," << y << "에 가로 " 
                  << width << " 세로 " << height << "인 사각형을 그려라.\n";
    }
};

int main() {
    Rectangle rect(2, 3, 100, 200);
    rect.draw();
    return 0;
}
