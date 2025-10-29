#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    int B;

    cin  >> N >> B;

    vector<char> B_vecotr;
    int current_digit;

    while (N > 0L){
        current_digit = N % B;
        N = N / B;
        
        if (current_digit < 10) B_vecotr.push_back('0' + current_digit);
        else B_vecotr.push_back('A' + current_digit - 10);
    }

    for (int i=B_vecotr.size()-1; i>=0; i--){
        cout << B_vecotr[i];
    }

    return 0;
}