#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> input_numbers;
    for (int i=0; i < N; i++){
        int num;
        cin >> num;
        input_numbers.push_back(num);
    }

    sort(input_numbers.begin(), input_numbers.end());

    int person=0;
    int total =0;

    for (int i=0; i < N; i++){
        person += input_numbers[i];
        total += person;
    }

    cout << total << '\n';

    return 0;
}