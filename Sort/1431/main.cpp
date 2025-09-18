#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool order_well (string a, string b) {
    if (a.size() < b.size()){
        return true;
    }
    else if (a.size() > b.size()){
        return false;
    }
    else {
        int number_a = 0;
        int number_b = 0;

        for (int i=0; i < a.size(); i++){
            char char_a = a[i];
            if ('0' <= char_a && char_a <= '9'){
                number_a += int(char_a - '0');
            }
        }

        for (int i=0; i < b.size(); i++){
            char char_b = b[i];
            if ('0' <= char_b && char_b <= '9'){
                number_b += int(char_b - '0');
            }
        }

        if (number_a < number_b){
            return true;
        }
        else if (number_a > number_b){
            return false;
        }
        else {
            return a < b;
        }
    }
}

int main () {
    int input_num;
    cin >> input_num;

    vector<string> input_strings;
    for (int i=0; i<input_num; i++){
        string input_string;
        cin >> input_string;
        input_strings.push_back(input_string);
    }

    sort(input_strings.begin(), input_strings.end(), order_well);

    for (int i=0; i<input_num; i++){
        cout << input_strings[i] << endl;
    }

    return 0;
}