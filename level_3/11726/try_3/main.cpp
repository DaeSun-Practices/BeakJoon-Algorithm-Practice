#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    int result_array[N+1];
    result_array[1] = 1;
    result_array[2] = 2;

    for (int i=3; i<=N; i++){
        result_array[i] = (result_array[i-2] + result_array[i-1]) % 10007;
    }



    cout << result_array[N]  << '\n';
    

    return 0;
}
