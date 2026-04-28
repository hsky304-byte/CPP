#include <iostream>
#include <string>
#include <fstream>

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

    inline void load(string filename) {
        ifstream fin(filename);
        if (!fin) return;
        nWords = 0;
        string e, k;
        while (fin >> e >> k) {
            add(e, k);
        }
        fin.close();
    }

    inline void store(string filename) {
        ofstream fout(filename);
        if (!fout) return;
        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }
        fout.close();
    }

    inline void print() {
        cout << "\n--- 단어장 목록 (" << nWords << "개) ---" << endl;
        for (int i = 0; i < nWords; i++) {
            cout << i + 1 << ". " << words[i].eng << " : " << words[i].kor << endl;
        }
    }

    // 영어 단어 반환
    inline string getEng(int id) {
        if (id >= 0 && id < nWords) return words[id].eng;
        return "";
    }

    // 한글 뜻 반환
    inline string getKor(int id) {
        if (id >= 0 && id < nWords) return words[id].kor;
        return "";
    }
};

// 메인 함수 요구사항 (3번)
int main() {
    MyDic dic;
    dic.add("school", "학교");
    dic.add("computer", "컴퓨터");
    dic.add("programming", "프로그래밍");

    dic.print();
    dic.store("my_words.txt");

    // getter 기능 테스트
    cout << "\n0번 인덱스의 영어: " << dic.getEng(0) << endl;
    cout << "1번 인덱스의 한글: " << dic.getKor(1) << endl;

    return 0;
}