#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    set<string> N_set;


    for (int i=0;i<N;i++){
        string input_name;
        cin >> input_name;
        N_set.insert(input_name);
    }

    vector<string> output_vector;

    for (int i=0;i<M;i++){
        string candidate_name;
        cin >> candidate_name;

        if (N_set.find(candidate_name) != N_set.end()){
            output_vector.push_back(candidate_name);
            N_set.erase(candidate_name);
        }
    }

    sort(output_vector.begin(), output_vector.end());
    
    cout << output_vector.size() << '\n';
    for (int i=0 ; i < output_vector.size(); i++){
        cout << output_vector[i] << '\n';
    }

}