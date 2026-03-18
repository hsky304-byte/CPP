#include <iostream>
using namespace std;

int main() {
    for(int i = 1; i <= 5; i++) {
        // 공백 출력
        for(int s = 1; s <= 5 - i; s++) {
            cout << "  ";
        }
        // 숫자 출력 (역순)
        for(int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}