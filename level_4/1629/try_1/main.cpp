#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    cin >> A >> B >> C;

    long long start = ((A % C) * (A % C)) % C;
    B -= 2;

    for (int _=0; _<B; _++){
        start = (start * A) % C;
    }

   

    cout << start;
 

    return 0;
}