#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<vector<int>> weight_table;

    for (int i=0; i<V+1; i++){
        weight_table.push_back(vector<int>(V+1, -1));
        weight_table[i][i] = 0;
    }


    int start_node_index;
    cin >> start_node_index;


    vector<pair<int, pair<int, int>>> edges;
    int u,v,w;
    for (int _=0; _<E; _++){
        cin >> u >> v >> w;
        edges.push_back(pair<int, pair<int, int>>(w,  pair<int, int>(u, v)));

        if (weight_table[u][v] == -1 || weight_table[u][v] > w){
            weight_table[u][v] = w;
        }
    }

    
    vector<int> shortest_cost(V+1, -1);
    shortest_cost[start_node_index] = 0;

    /*
    sort(edges.begin(), edges.end());
    for (int edge_index = 0; edge_index<E; edge_index++){

    }
    */

    /*
    for (int target_node_index = 1; target_node_index < V+1; target_node_index++){
        if (target_node_index == start_node_index)
        {
            continue;
        }

        
        
    }
    */

    for (int i=1; i<=V; i++){
        for (int j=1; j<=V; j++){
            
        }
    }
    
        

    return 0;
}