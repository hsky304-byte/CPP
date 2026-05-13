// Monster.h의 클래스 내부에 추가될 내용들
class Monster {
    // ... 기존 멤버들 ...
    int nEnergy;
    static int sMonCount; //

public:
    Monster(string n, string i, int x, int y) : name(n), icon(i), x(x), y(y), nEnergy(100) {
        sMonCount++; // 생성 시 증가
    }
    ~Monster() { sMonCount--; } // 소멸 시 감소
    
    int getEnergy() { return nEnergy; }
    string getName() { return name; }
    
    static void printCount() {
        cout << " 현재 살아있는 몬스터 수: " << sMonCount << endl;
    }
    
    // (1) 에너지를 표시하는 print 함수
    void print() {
        cout << icon << ":" << name << "(E:" << nEnergy << ")  ";
    }
    // ... move 함수 등 ...
};