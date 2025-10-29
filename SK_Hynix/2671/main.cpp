#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    regex pattern("(100+1+|01)+");

    if (regex_match(s, pattern)) 
        cout << "SUBMARINE\n";
    else 
        cout << "NOISE\n";

    return 0;
}
