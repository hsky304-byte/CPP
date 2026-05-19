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
    // [2번] 부모 생성자 호출 및 자식 멤버 초기화 리스트 구현
    Rectangle(int xx, int yy, int w, int h) : Point(xx, yy), width(w), height(h) { }

    // 변수 확인용 함수
    void printInfo() {
        std::cout << "부모 변수(x,y): " << x << "," << y << "\n";
        std::cout << "자식 변수(w,h): " << width << "," << height << "\n";
    }
};

int main() {
    // 생성자를 통해 한 번에 초기화
    Rectangle rect(2, 3, 100, 200);
    
    std::cout << "(2)번 단계: 멤버 초기화 리스트 생성자 실행\n";
    rect.printInfo();
    return 0;
}