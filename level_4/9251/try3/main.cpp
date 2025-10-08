#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string string_1;
    string string_2;

    cin >> string_1;
    cin >> string_2;

    int n = string_1.size();
    int m = string_2.size();

    int lcs_table[n+1][m+1];
    for  (int j=0; j<=m; j++)
        lcs_table[0][j] = 0;
    
    for (int i=0; i<=n; i++)
        lcs_table[i][0] = 0;

    for (int i=1; i<=n; i++){
        char char1 = string_1[i-1];

        for  (int j=1; j<=m; j++){
            char char2 = string_2[j-1];

            if (char1 == char2){
                lcs_table[i][j] = lcs_table[i-1][j-1] + 1;
            }
            else {
                lcs_table[i][j] = max(lcs_table[i-1][j], lcs_table[i][j-1]) ;
            }
        }
    }

    cout << lcs_table[n][m];

    return 0;
}