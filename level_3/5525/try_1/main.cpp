#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string parse = "I";

    for (int i=0; i < N; i++){
        parse += "OI";
    }
    int parse_length = 1 + 2 * N;



    int M;
    cin >> M;

    string total_string;
    cin >> total_string;

    int awnser = 0;

    for (int i=0; i <= M-(2*N + 1); i++) {
        string parsed = total_string.substr(i,parse_length);

        
        if (parsed == parse){

            awnser++;
        }
    }

    cout << awnser << '\n';


    return 0;
}