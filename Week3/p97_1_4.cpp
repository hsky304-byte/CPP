#include <iostream>
using namespace std;

int main() {
    for(int i = 1; i <= 5; i++) {
        // 공백
        for(int s = 1; s <= 5 - i; s++) {
            cout << "  ";
        }

        // 감소 (i → 1)
        for(int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        // 증가 (2 → i)
        for(int j = 2; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }
    return 0;
}