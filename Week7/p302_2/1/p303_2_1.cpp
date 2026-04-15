#include <iostream>
#include <string>

using namespace std;

const int MAXWORDS = 100;

// (1) 단어 쌍 구조체
struct WordPair {
    string eng;
    string kor;
};

// (2) MyDic 클래스 (inline 구현)
class MyDic {
private:
    WordPair words[MAXWORDS];
    int nWords;

public:
    MyDic() : nWords(0) {} // 생성자

    inline void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        } else {
            cout << "단어장 용량 초과!" << endl;
        }
    }

    inline void print() {
        cout << "\n--- 단어장 목록 (" << nWords << "개) ---" << endl;
        for (int i = 0; i < nWords; i++) {
            cout << words[i].eng << " : " << words[i].kor << endl;
        }
    }
};

int main() {
    MyDic dic;
    dic.add("apple", "사과");
    dic.add("student", "학생");
    dic.print();
    return 0;
}