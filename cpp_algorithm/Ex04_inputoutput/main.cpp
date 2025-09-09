#include <iostream>

using namespace std;

int main () {
    cout << "아무원하는 단어를 입력해주세요\n";

    char name[100];

    cin >> name;

    cout << name;

    char user_input[500];
    cin.getline(user_input, sizeof(user_input)); // 무조건 문자열 리터럴로 받아옴
    cin.ignore(100, '\n'); // 최대 100글자까지만 입력 받아서 무시하겠다. 또는 \n이 있으면 그때부터 무시하겠다.
}