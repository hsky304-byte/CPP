#include <iostream>

int main()
{
    for(int i = 1; i<=5; ++i)
    {
        //i=1
        //std::cout << i << "\n";
        for(int j = 1; j <= i; ++j)
        {
            std::cout <<j;
        }
        std::cout << "\n";
    }
}

#include <iostream>
using namespace std;

int main() {
    for(int i = 5; i >= 1; i--) {
        for(int j = 5; j >= 6 - i; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

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