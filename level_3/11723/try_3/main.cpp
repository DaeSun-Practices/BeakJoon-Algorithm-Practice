#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    int S = 0;  // 비트마스크로 집합 표현 (1~20 → 1<<20 사용)
    string cmd;
    int x;

    while (M--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            S |= (1 << (x - 1));
        }
        else if (cmd == "remove") {
            cin >> x;
            S &= ~(1 << (x - 1));
        }
        else if (cmd == "check") {
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << "\n";
        }
        else if (cmd == "toggle") {
            cin >> x;
            S ^= (1 << (x - 1));
        }
        else if (cmd == "all") {
            S = (1 << 20) - 1; // {1,2,...,20}
        }
        else if (cmd == "empty") {
            S = 0;
        }
    }
    return 0;
}
