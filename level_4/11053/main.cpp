#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> number_n;
    vector<int> route_length;
    for (int _=0;_<N;_++){
        int x;
        cin >> x;
        number_n.push_back(x);
        route_length.push_back(1);
    }

    for (int i=0; i<N; i++){
        int current_max = 0;

        for (int j=0; j<i; j++){
            if (number_n[j] < number_n[i]){
                current_max = max(current_max, route_length[j]);
            }
        }

        route_length[i] = current_max + 1;
    }

    int awnser = 0;
    for (int i=0; i<N; i++){
        if (route_length[i] > awnser){
            awnser = route_length[i];
        }
    }
    
    cout << awnser;

    return 0;
}