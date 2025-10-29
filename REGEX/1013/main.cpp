#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    regex pattern ("(100+1+|01)+");

    int N;
    cin >> N;

    string signal_string;

    for (int _=0; _<N; _++){
        cin >> signal_string;

        if (regex_match(signal_string, pattern)){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    
    return 0;
}