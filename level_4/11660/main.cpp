#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int number_table[N][N];
    int cummulated_table [N][N];

    int x;
    for (int j=0; j<N; j++){
        cin >> x;
        if (j==0) {
            number_table[0][0] = x;
            cummulated_table[0][0] = x;
        }
        else{
            number_table[0][j] = x;
            cummulated_table[0][j] = x + cummulated_table[0][j-1];
        }
    }

    for (int i=1; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> x;
            if (j==0) {
                number_table[i][0] = x;
                cummulated_table[i][0] = x + cummulated_table[i-1][0];
            }
            else{
                number_table[i][j] = x;
                cummulated_table[i][j] = x + cummulated_table[i][j-1] + cummulated_table[i-1][j] - cummulated_table[i-1][j-1];
            }
        }
    }

    /*
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << cummulated_table[i][j] << " ";
        }
        cout << "\n";
    }
    */
   
    int x1, y1, x2, y2;
    for (int awnser_index=0; awnser_index < M; awnser_index++){
        cin >> x;
        x1 = x-2;

        cin >> x;
        y1 = x-2;

        cin >> x;
        x2 = x-1;

        cin >> x;
        y2 = x-1;
    
        int a = cummulated_table[x2][y2];
        int b = 0;
        if (x1 >= 0){
            b = cummulated_table[x1][y2];
        }

        int c = 0;
        if (y1 >= 0){
            c = cummulated_table[x2][y1];
        }

        int d = 0;
        if (x1 >= 0 && y1 >= 0){
            d = cummulated_table[x1][y1];
        }

        int awsner = a - b - c + d;
        cout << awsner << '\n';
    }

    return 0;
}