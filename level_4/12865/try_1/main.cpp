#include <bits/stdc++.h>

using namespace std;

bool stuff_sort (pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first ){
        return true;
    }
    else if (a.first > b.first ){
        return false;
    }
    else {
        if (a.second > b.second ){
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

    vector<int> weight_vector;
    for (int i=1; i<=N; i++){
        int min_wegiht = 0;
        for (int candidate_n=0; candidate_n<i; candidate_n++){
            min_wegiht += stuff_list[candidate_n].first;
        }

        //cout << min_wegiht << '\n';

        if (min_wegiht <= K) {
            weight_vector.push_back(i);
        }
        else {
            break;
        }
    }


    int max_value = 0;
    
    for (int i=0; i < weight_vector.size(); i++){
        vector<int> mask_vector;

        int sttuf_number =  weight_vector[i] ;

        for (int _=0; _ < N - sttuf_number; _++) {
            mask_vector.push_back(0);
        }

        for (int _=0; _ < sttuf_number; _++) {
            mask_vector.push_back(1);
        }


        do {
            int total_wegiht = 0;
            int total_value = 0;

            for (int j=0; j<N; j++){
                if (mask_vector[j]){
                    total_wegiht += stuff_list[j].first;
                    total_value += stuff_list[j].second;
                }
            }

            if (total_wegiht <= K) {
                max_value = max(max_value, total_value);
            }

        } while (next_permutation(mask_vector.begin(), mask_vector.end(), less()));

        //cout << weight_vector[i] << '\n';

    }
    

    cout << max_value;
    
    



    return 0;
}