#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> coin_list;
    for (int i=0;i<N;i++){
        int coin;
        cin >> coin;

        coin_list.push_back(coin);
    }

    int coin_count = 0;

    for (int i=0;i<N;i++){
        int current_coin = coin_list[N-1-i];

        while (true) {
            if (current_coin > K) {
                break;
            }

            K -= current_coin;
            coin_count++;
        }

        if (K==0){
            break;
        }
    }

    cout << coin_count << '\n';

    return 0;
}