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
    long long current_sum = 0;

    while (true) {
        if (current_sum < S) {
            if (right == N) break;
            current_sum += arr[right];
            right++;
            
        }
        else if (current_sum >= S)  {
            if (left == N) break;
            min_index_num = min(min_index_num, right- left);
            current_sum -= arr[left];
            left++;
        }
       
    }

    if (min_index_num == INT_MAX) cout << 0;
    else cout << min_index_num;

    



    return 0;
}