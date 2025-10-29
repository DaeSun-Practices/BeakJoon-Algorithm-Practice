#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;

    cin >> N >> M;

    int arr[N];

    int x;
    for (int i=0; i<N; i++){
        cin >> x;
        arr[i] = x;
    }

    long long current_total = 0;
    long long total_count = 0;
    int left = 0 ; 
    int right = 0 ;

    while (true) {
        if (current_total > M) {
            current_total -= arr[left];
            left++;
        }
        else if (current_total == M){
            total_count++;
            
            current_total -= arr[left];
            left++;
        }
        else {
            if (right >= N) break;

            current_total += arr[right];
            right++;
        }
    }




    cout << total_count;


    return 0;
}
