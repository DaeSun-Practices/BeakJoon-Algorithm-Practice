#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left_index = 0;
    int right_index = n-1;

    int best_left = left_index;
    int best_right = right_index;

    int current_num = arr[left_index] + arr[right_index];
    int best = abs(current_num);

    while (left_index < right_index) {
        current_num = arr[left_index] + arr[right_index];

        if (best > abs(current_num)) {
            best = abs(current_num);
            best_left = left_index;
            best_right = right_index;
        }

        if (current_num > 0) {
            right_index--;
        }
        else if (current_num < 0){
            left_index++;
        }
        else{
            break;
        }
    }

    cout << arr[best_left] << " " <<  arr[best_right] ;

    return 0;
}
