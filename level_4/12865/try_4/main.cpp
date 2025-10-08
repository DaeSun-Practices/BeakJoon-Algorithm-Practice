#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> W(N + 1), V(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    // dp[w] = "무게 w일 때 얻을 수 있는 최대 가치"
    vector<int> dp(K + 1, 0);

    // 모든 물건을 하나씩 고려
    for (int i = 1; i <= N; i++) {
        // 배낭 무게를 거꾸로 순회 (0/1 배낭 핵심)
        for (int w = K; w >= W[i]; w--) {
            // i번째 물건을 넣을지 말지 결정
            dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
        }
    }

    cout << dp[K] << '\n';
    return 0;
}
