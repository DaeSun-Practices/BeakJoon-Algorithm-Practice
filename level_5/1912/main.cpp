#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long arr[N];
    long long dp[N];
    long long x;
    cin >> x;
    arr[0] = x;
    dp[0] = max(0LL, x);

    long long awnser = x;

    for (int i=1; i<N; i++){
        cin >> x;
        arr[i] = x;
        dp[i] = max(dp[i-1]+x, x);

        awnser = max(awnser, dp[i]);
    }

    cout << awnser;
    


    return 0;
}