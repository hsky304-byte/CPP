// 생성자 본체에서 대입하는 방식
    MyTime(int h = 0, int m = 0, int s = 0, int ms = 0) {
        hour = h;
        min = m;
        sec = s;
        mil = ms;
        cout << "생성자 본체에서 대입을 이용한 생성자 호출" << endl;
    }