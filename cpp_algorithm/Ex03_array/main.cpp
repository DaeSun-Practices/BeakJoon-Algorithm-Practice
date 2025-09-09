#include <iostream>

using namespace std;

int main () {
    int my_array[3] = {1, 2, 3};

    for (int i = 0; i < 3; i++ ) {
        cout << my_array[i] << " ";
    }
    cout << endl;


    // "Hello, World!"는 엄밀히 말하면 14글자이다.
    // 맨 마지막에 null character가 \0으로 문자열의 종료를 알려준다
    char name[75] = "Hello, World!"; //이러면 강제로 75개가 할당된다.
    cout << name << " " << sizeof(name) << endl;

    
}