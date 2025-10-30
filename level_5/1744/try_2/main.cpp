#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> pos, neg;
    bool hasZero = false;
    int oneCount = 0;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 1) pos.push_back(x);
        else if (x == 1) oneCount++;
        else if (x == 0) hasZero = true;
        else neg.push_back(x);
    }

    // 정렬
    sort(pos.begin(), pos.end(), greater<int>()); // 큰 수부터
    sort(neg.begin(), neg.end());                 // 작은 수부터 (ex. -10, -5, -2)

    long long sum = 0;

    // 양수 > 1 처리
    for (int i = 0; i + 1 < (int)pos.size(); i += 2) {
        sum += pos[i] * pos[i + 1];
    }
    if (pos.size() % 2 == 1) sum += pos.back(); // 홀수 남으면 그냥 더하기

    // 음수 처리
    for (int i = 0; i + 1 < (int)neg.size(); i += 2) {
        sum += neg[i] * neg[i + 1];
    }
    if (neg.size() % 2 == 1) { // 음수가 하나 남은 경우
        if (!hasZero) sum += neg.back(); // 0 없으면 그냥 더함
        // 0 있으면 neg.back() * 0 = 0 → 추가 안 함
    }

    // 1은 전부 더하기
    sum += oneCount;

    cout << sum << "\n";
    return 0;
}
