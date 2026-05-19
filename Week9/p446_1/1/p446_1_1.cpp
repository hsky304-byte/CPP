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

// [1번] Point 클래스를 상속받고 width, height 멤버 추가
class Rectangle : public Point {
public:
    int width;
    int height;
    
    // 기본 부모 생성자를 호출하기 위해 임시로 매개변수 없는 생성자 지정
    Rectangle() : Point(0, 0), width(0), height(0) { }
};

int main() {
    Rectangle rect;
    rect.width = 100;
    rect.height = 200;
    
    std::cout << "(1)번 단계: Rectangle 객체 생성 및 멤버 추가 완료\n";
    std::cout << "가로: " << rect.width << ", 세로: " << rect.height << "\n";
    
    // 부모의 함수도 상속받았으므로 호출 가능
    rect.draw(); 
    return 0;
}