#include <bits/stdc++.h>

using namespace std;

int test_func(int n){
    if (n==1) {
        return 1;
    }
    else if (n==2){
        return 2;
    }
    else if (n==3){
        return 4;
    }
    
    return test_func(n-2) + test_func(n-1) + test_func(n-3);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    for (int i=0; i<N; i++){
        int k;
        cin >> k;
        cout <<  test_func(k) << '\n';
    }

    return 0;
}