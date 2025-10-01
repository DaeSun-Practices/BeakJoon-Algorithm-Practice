#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i=0; i< N; i++){
        int problem_n;
        cin >> problem_n;


        int zero_array[problem_n+1];
        int one_array[problem_n+1];

        zero_array[0] = 1;
        zero_array[1] = 0;

        one_array[0] = 0;
        one_array[1] = 1;

        
        

        for (int i=2; i<=problem_n; i++){
            zero_array[i] = zero_array[i-1] + zero_array[i-2];
            one_array[i] = one_array[i-1] + one_array[i-2];
        }


        cout << zero_array[problem_n] << ' '<< one_array[problem_n] << '\n';
    }



    return 0;
}