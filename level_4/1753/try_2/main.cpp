#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;


    int start_node_index;
    cin >> start_node_index;


    map<int, map<int, int>> edges;
    for (int i=1; i<V+1; i++){
        edges[i] = map<int, int>({});
    }
    int u,v,w;
    for (int _=0; _<E; _++){
        cin >> u >> v >> w;

        if (edges[u][v] != NULL){
            if (edges[u][v] > w){
                edges[u][v] = w;
            }
        }
        else{
            edges[u][v] = w;
        }
    }

    
    vector<int> shortest_cost(V+1, INFINITY);
    vector<bool> has_visited(V+1, false);
    shortest_cost[start_node_index] = 0;

    for (int _=0; _<V; _++){
        int current_u_index;
        int min_cost = INFINITY;

        for (int i=1; i<=V; i++){
            if (!has_visited[i] && min_cost > shortest_cost[i]){
                current_u_index = i;
                min_cost = shortest_cost[i];
            }
        }


        has_visited[current_u_index] = true;

        map<int, int> edges_map = edges[current_u_index];
        vector<pair<int, int>> sorted_vector;
        for (auto &kv : edges_map){
            sorted_vector.push_back(pair<int, int>(kv.second, kv.first));
        }

        sort(sorted_vector.begin(), sorted_vector.end());

       

        for (auto &edge : sorted_vector){
            int wegiht = edge.first;
            int next_node = edge.second;

           
            if (shortest_cost[next_node] > shortest_cost[current_u_index] + wegiht){
                shortest_cost[next_node] = shortest_cost[current_u_index] + wegiht;
            }
        }
    }

    for (int i=1; i<=V; i++){
        if (!has_visited[i]){
            cout << "INF" << '\n';
        }
        else
            cout << shortest_cost[i] << '\n';
    }

    return 0;
}