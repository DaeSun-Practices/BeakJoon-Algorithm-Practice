#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int grade_array[N];

    for (int i = 0; i < N; i++){  
        int grade;
        cin >> grade;
        grade_array[i]=grade;
    }

    int total_array[N];
    total_array[0] = grade_array[0];
    total_array[1] = grade_array[0] + grade_array[1];
    total_array[2] = max(grade_array[2] + grade_array[1], grade_array[2] + grade_array[0]);

    for (int i=3; i<N; i++){
        total_array[i] = max(grade_array[i] + total_array[i-2], grade_array[i] + grade_array[i-1]+total_array[i-3]);
    }

    cout << total_array[N-1] << '\n';

    return 0;
}