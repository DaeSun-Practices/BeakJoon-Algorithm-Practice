#include <bits/stdc++.h>

using namespace std;


void fibonacci(int n, int * paper) {
    if (n == 0) {
        paper[0]++;
        return;
    } else if (n == 1) {
        paper[1]++;
        return;
    } else {
        fibonacci(n-1, paper);
        fibonacci(n-2, paper);
        return;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i=0; i< N; i++){
        int paper[2] = {0, 0};
        
        int problem_n;
        cin >> problem_n;

        fibonacci(problem_n, paper);

        cout << paper[0] << ' '<< paper[1] << '\n';
    }



    return 0;
}