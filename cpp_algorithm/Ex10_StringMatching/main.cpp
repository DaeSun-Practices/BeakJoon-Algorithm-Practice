
#include <iostream>

using namespace std;

const int kMaxStr = 100; //전역변수



int main () {
    const char str1[kMaxStr] = "STOP";

    char user_input[kMaxStr];

    while (true) {
        cout << "문자를 입력하세요: " ;
        cin >> user_input;

        bool is_match = true;
        for (int i=0; i<4; i++){
            if (str1[i] != user_input[i]) {
                is_match = false;
                break;
            }
        }

        if (is_match) 
            break;
    }

    return 0;
}