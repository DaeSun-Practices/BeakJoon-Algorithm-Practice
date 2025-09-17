
#include <iostream>
#include <random> // 난수 생성

using namespace std;

int main () {
    // 난수 생성
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 99); // [1, 99]

    int number = distrib(gen);

    while (true) {
        cout << "입력: ";

        int user_guess;
        cin >> user_guess;

        if (user_guess > number) {
            cout << "너무 커요! \n";
        }

        else if (user_guess < number) {
            cout << "너무 작아요! \n";
        }

        else {
            cout << "정답! \n";
            break;
        }

    }


    return 0;
}