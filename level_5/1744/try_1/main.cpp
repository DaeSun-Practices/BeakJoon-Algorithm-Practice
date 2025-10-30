#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long awsner = 0;
    vector<int> minus_vector;
    vector<int> zero_vector;
    vector<int> one_vector;
    vector<int> plus_vector;

    int x;
    for (int i=0; i<N; i++){
        cin >> x;

        if (x == 0) {
            zero_vector.push_back(x);
        }
        else if (x == 1) {
            one_vector.push_back(x);
        }
        else if (x > 1) {
            plus_vector.push_back(x);
        }
        else {
            minus_vector.push_back(x);
        }
    }

    sort(plus_vector.begin(), plus_vector.end());
    sort(minus_vector.begin(), minus_vector.end(), greater());

    
    for (int y : plus_vector) cout << y << " ";
    cout << endl;
    for (int y : minus_vector) cout << y << " ";
    cout << endl;
    

    while (plus_vector.size() > 1){
        long long y = plus_vector.back(); plus_vector.pop_back();
        y *= plus_vector.back(); plus_vector.pop_back();

        awsner += y;
    }

    while (minus_vector.size() > 1){
        long long y = minus_vector.back(); minus_vector.pop_back();
        y *= minus_vector.back(); minus_vector.pop_back();

        awsner += y;
    }

    if (minus_vector.size() == 1 && zero_vector.size() == 0) {
        awsner += minus_vector[0];
    }

    awsner += one_vector.size();

    cout << awsner;


    return 0;
}