#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int cal_count = 0;
    int input_num;

    cin >> input_num;
    while (input_num > 1){
        if (input_num % 3 == 0) {
            input_num /= 3;
            cal_count++;
        }
        else if ((input_num - 1) % 3 == 0) {
            input_num--;
            cal_count++;
        }

        else if (input_num % 2 == 0) {
            input_num /= 2;
            cal_count++;
        }
        else {
            input_num--;
            cal_count++;
        }
    }

    cout << cal_count;
    return 0;
}