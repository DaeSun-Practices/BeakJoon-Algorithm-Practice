#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int parrent_array[N+1];
    int cost_array[N+1];
    int semi_roots[N+1];
    unordered_map<int, int> semi_root_cost_map;

    parrent_array[1] = 0;
    cost_array[1] = 0;
    semi_roots[1] = 0;

    int parent_node, child_node, weight;
    for (int _=0; _<N-1; _++){
        cin >> parent_node >> child_node >> weight;

        parrent_array[child_node] = parent_node;
        cost_array[child_node] = cost_array[parent_node] + weight;

        if (semi_roots[parent_node] == 0){
            semi_roots[child_node] = child_node;
            semi_root_cost_map[child_node] = cost_array[child_node];
        }
        else {
            int semi_root_node = semi_roots[parent_node];
            semi_roots[child_node] = semi_root_node;
            semi_root_cost_map[semi_root_node] = max(cost_array[child_node], semi_root_cost_map[semi_root_node]);
        }

        //cout << child_node << " " << parrent_array[child_node] << " " << cost_array[child_node] << " " << semi_roots[child_node]  << '\n';
        //cout <<  semi_root_cost_map[semi_roots[child_node]] << '\n';
    }   

    /*
    for (int i=1; i<=N; i++){
        cout << i << " " << parrent_array[i] << " " << cost_array[i] << " " << semi_roots[i]  << '\n';
    }*/


    vector<int> half_zilm;
    for (auto &kv : semi_root_cost_map){
        half_zilm.push_back(kv.second);
    }

    sort(half_zilm.begin(), half_zilm.end());

    int awnser = 0;
    awnser += half_zilm.back();
    half_zilm.pop_back();
    awnser += half_zilm.back();

    cout << awnser;


    return 0;
}