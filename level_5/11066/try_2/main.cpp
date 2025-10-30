#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<62);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if(!(cin >> T)) return 0;


    while (T--) {
        int K;
        cin >> K;
        vector<ll> a(K+1);
        for (int i = 1; i <= K; ++i) cin >> a[i];
        
        // prefix sums
        vector<ll> ps(K+1, 0);
        for (int i = 1; i <= K; ++i) ps[i] = ps[i-1] + a[i];
        auto range_sum = [&](int l, int r)->ll { return ps[r] - ps[l-1]; };
        
        // dp and opt
        vector<vector<ll>> dp(K+2, vector<ll>(K+2, 0));
        vector<vector<int>> opt(K+2, vector<int>(K+2, 0));
        
        for (int i = 1; i <= K; ++i) {
            dp[i][i] = 0;
            opt[i][i] = i;
        }
        
        for (int len = 2; len <= K; ++len) {
            for (int i = 1; i + len - 1 <= K; ++i) {

                int j = i + len - 1;
                dp[i][j] = INF;

                // Knuth: opt[i][j-1] <= opt[i][j] <= opt[i+1][j]
                int start = opt[i][j-1];
                int end = opt[i+1][j];
                if (start == 0) start = i; 
                if (end == 0) end = j-1;
                if (start > end) swap(start, end);

                // restrict to [i, j-1]
                start = max(start, i);
                end = min(end, j-1);

                for (int k = start; k <= end; ++k) {
                    ll cost = dp[i][k] + dp[k+1][j] + range_sum(i, j);
                    
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        opt[i][j] = k;
                    }
                }

            }
        }
        
        cout << dp[1][K] << '\n';
    }
    return 0;
}
