#include <bits/stdc++.h>

using namespace std;

int factorial(int n){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    if (n==1){
        return 1;
    }

    if (n==2){
        return 2;
    }

    return factorial(n-2) + factorial(n-1);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;



    cout << factorial (N) % 10007 << '\n';
    

    return 0;
}
