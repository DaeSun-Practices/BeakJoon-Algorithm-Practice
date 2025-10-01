#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    
    long long angle_array[101];
    angle_array[0] = 0;
    angle_array[1] = 1;
    angle_array[2] = 1;
    angle_array[3] = 1;

    for (int j=4; j<=100; j++){
        angle_array[j] = angle_array[j-2] + angle_array[j-3];
    }

    
    

    for (int i=0; i<N; i++){
        int k;
        cin >> k;

        cout <<  angle_array[k] << '\n';
    }

    return 0;
}