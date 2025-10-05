#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int tree_node_array[N+1];
    for (int i=1; i <= N; i++){
        tree_node_array[i] = i;
    }

    for (int _=0; _ < N-1; _++){
        int src_node, trg_node;
        cin >> src_node >> trg_node;

        if (src_node != 1 && tree_node_array[src_node] == src_node){
            tree_node_array[src_node] = trg_node;
        }
        
        else if (trg_node != 1 && tree_node_array[trg_node] == trg_node){
            tree_node_array[trg_node] = src_node;
        }
    }

    for (int i=2; i<=N; i++){
        cout << tree_node_array[i] << '\n';
    }

    return 0;
}