#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    int number_array[N];
    for (int i=0; i<N; i++) {
        int number;
        cin >> number;

        number_array[i] = number;
    }

    long long sum_array[N];
    sum_array[0] = number_array[0];
    for (int i=1; i<N; i++) {
        sum_array[i] = number_array[i] + sum_array[i-1];
    }

    for (int i=0; i<M; i++) {
        int start_index, end_index;

        cin >> start_index >> end_index;

        if (start_index-2 >=0){
            long long  awsner = sum_array[end_index-1] - sum_array[start_index-2];
            cout << awsner << '\n';
        }
        else{
            long long  awsner = sum_array[end_index-1];
            cout << awsner << '\n';
        }
       
    }
}