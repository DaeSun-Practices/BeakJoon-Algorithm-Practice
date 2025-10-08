#include <bits/stdc++.h>

using namespace std;

bool stuff_sort (pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second ){
        return true;
    }
    else if (a.second < b.second ){
        return false;
    }
    else {
        if (a.first < b.first ){
            return true;
        }
        else {
            return false;
        }
    }
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> stuff_list;
    int w, v;
    for (int _=0; _<N; _++){
        cin >> w >> v;
        if (w <= K)
            stuff_list.push_back(pair<int, int> (w, v));
    }

    sort(stuff_list.begin(), stuff_list.end(), stuff_sort);
    N = stuff_list.size();
    
    /*
    for (int i=0; i<N; i++){
        cout << stuff_list[i].first << " " << stuff_list[i].second << '\n';
    }
    */



    pair<int, int> pack_array[N];
    pack_array[N-1] = pair<int, int> (stuff_list[N-1].first, stuff_list[N-1].second);

    for (int i=0; i<N-1; i++){
        int current_weight = stuff_list[i].first;
        int current_value = stuff_list[i].second;

        int candidate_index = i+1;
        while (current_weight < K && candidate_index < N){
            if ()



            candidate_index++;
        }

        if (current_weight == K) {
            cout << current_value;
            return 0;
        }
    }
   

    
    



    return 0;
}