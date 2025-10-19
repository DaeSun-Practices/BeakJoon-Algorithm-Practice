#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0;
    int right = n - 1;

    long long best_sum = LLONG_MAX;
    long long ans_left = arr[left], ans_right = arr[right];

    while (left < right) {
        long long sum = arr[left] + arr[right];

        if (abs(sum) < abs(best_sum)) {
            best_sum = sum;
            ans_left = arr[left];
            ans_right = arr[right];
        }

        if (sum < 0)
            left++;
        else if (sum > 0)
            right--;
        else
            break; // 완벽히 0인 경우 즉시 종료
    }

    cout << ans_left << " " << ans_right << "\n";
    return 0;
}
