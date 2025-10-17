#include <bits/stdc++.h>

using namespace std;

long long PRIME_NUMBER = 1000000007;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long  n;
    cin >> n;

    if (n == 0){
        cout << 0;
        return 0;
    }

    if (n == 1) {
        cout << 1;
        return 0;
    }

    long long n_minas_2 = 1;
    long long n_minas_1 = 0;
    long long temp;

    for (long long i=2; i<=n; i++){
        temp = (n_minas_1 + n_minas_2) % PRIME_NUMBER;
        n_minas_1 = n_minas_2;
        n_minas_2 = temp;
    }

    cout << temp;

    
    return 0;
}