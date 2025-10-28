#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S;
    cin >> N >> S;
    int arr[N];
    int x;
    for (int i=0; i<N; i++){
        cin >> x;
        arr[i] = x;
    }

    int left=0;
    int right=0;
    int min_index_num = INT_MAX;
    int current_sum = arr[0];

    while (true) {
        if (current_sum >=S){
            min_index_num = min(min_index_num, right- left +1);
        }


        if (current_sum <= S) {
            current_sum += arr[right];
            right++;
            if (right == N) break;
        }
        else {
            current_sum -= arr[left];
            left++;
            if (left == N) break;
        }
    }

    if (min_index_num == INT_MAX) cout << 0;
    else cout << min_index_num;

    



    return 0;
}