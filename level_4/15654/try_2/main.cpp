#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr.begin(), arr.end()); // 사전순을 위해 정렬

    // 조합 마스크 만들기 (앞에 1이 M개, 뒤에 0이 N-M개)
    vector<int> mask(N, 0);
    fill(mask.begin(), mask.begin() + M, 1);

    // 모든 조합 탐색
    do {
        vector<int> chosen;
        for (int i = 0; i < N; i++) {
            if (mask[i]) chosen.push_back(arr[i]);
        }

        // chosen 안에서 사전순 순열 생성
        sort(chosen.begin(), chosen.end());
        do {
            for (int i = 0; i < M; i++) {
                if (i) cout << ' ';
                cout << chosen[i];
            }
            cout << '\n';
        } while (next_permutation(chosen.begin(), chosen.end()));

    } while (prev_permutation(mask.begin(), mask.end()));

    return 0;
}
