#include <iostream>
#include <string>
#include <fstream> // 파일 입출력

using namespace std;

const int MAXWORDS = 100;

struct WordPair {
    string eng;
    string kor;
};

class MyDic {
private:
    WordPair words[MAXWORDS];
    int nWords;

public:
    MyDic() : nWords(0) {}

    inline void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    inline void print() {
        cout << "\n--- 단어장 목록 (" << nWords << "개) ---" << endl;
        for (int i = 0; i < nWords; i++) {
            cout << words[i].eng << " : " << words[i].kor << endl;
        }
    }

    // 파일 저장 기능
    inline void store(string filename) {
        ofstream fout(filename);
        if (!fout) return;
        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }
        fout.close();
        cout << "파일 저장 완료: " << filename << endl;
    }

    // 파일 불러오기 기능
    inline void load(string filename) {
        ifstream fin(filename);
        if (!fin) {
            cout << "파일을 찾을 수 없습니다." << endl;
            return;
        }
        nWords = 0; // 초기화 후 불러오기
        string e, k;
        while (fin >> e >> k) {
            add(e, k);
        }
        fin.close();
        cout << "파일 불러오기 완료: " << filename << endl;
    }
};

int main() {
    MyDic dic1;
    dic1.add("apple", "사과");
    dic1.add("student", "학생");
    dic1.store("words.txt"); // 파일로 저장

    MyDic dic2; // 새로운 단어장 객체
    dic2.load("words.txt"); // 파일에서 불러오기
    dic2.print(); // 제대로 불러와졌는지 확인

    return 0;
}