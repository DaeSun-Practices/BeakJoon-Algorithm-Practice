#include <bits/stdc++.h>

using namespace std;


long long recur (long long A,long long B, long long C){
    if (B == 1) {
        return A % C;
    }
    else if (B % 2 == 0){
        return (recur(A,B/2,C) * recur(A,B/2,C)) % C;
    }
    
    else if (B % 2 == 1) {
        return (A * ((recur(A,B/2,C) * recur(A,B/2,C)) % C)) % C;
    }

}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    cin >> A >> B >> C;


    long long awsner = recur(A,B,C);

    cout << awsner;
 

    return 0;
}