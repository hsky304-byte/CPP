#include <iostream>

class Point {
protected:
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

    // [3번] 부모의 draw() 함수를 사각형에 맞게 재정의
    void draw() {
        std::cout << x << "," << y << "에 가로 " 
                  << width << " 세로 " << height << "인 사각형을 그려라.\n";
    }
};

int main() {
    Rectangle rect(2, 3, 100, 200);
    
    std::cout << "(3)번 단계: 재정의된 draw() 함수 실행\n";
    rect.draw(); // 자식의 draw()가 호출됨
    return 0;
}