#include <bits/stdc++.h>

using namespace std;


pair<int, int> find_max (int N, int start_node, vector<pair<int, int>> tree_edges []) {
    bool visited[N+1] = {false};
    int cost[N+1] = {0};
    stack<int> s;

    visited[start_node] = true;
    s.push(start_node);

    while (!s.empty()){
        int current_node = s.top(); s.pop();

        vector<pair<int, int>> edges = tree_edges[current_node];
        for (pair<int, int> edge: edges){
            int next_node = edge.first;
            int weight = edge.second;

            if (!visited[next_node]){
                visited[next_node] = true;
                s.push(next_node);

                if (cost[next_node] < cost[current_node] + weight){
                    cost[next_node] = cost[current_node] + weight;
                }
            }
        }
    }

    int max_index = 0;
    int max_cost = 0;

    for (int i=1; i<=N; i++){
        if (cost[i] > max_cost){
            max_cost = cost[i] ;
            max_index = i;
        }
    }

    return pair<int, int>(max_index, max_cost);
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> tree_edges [N+1];
    int u,v,w;
    for (int _=0; _<N-1; _++){
        cin >> u >> v >> w;
        tree_edges[u].push_back(pair<int, int>(v, w));
        tree_edges[v].push_back(pair<int, int>(u, w));
    }

    pair<int, int> once_awnser = find_max(N, 1, tree_edges);
    //cout << once_awnser.first << " " << once_awnser.second << '\n';


    pair<int, int> twice_awnser = find_max(N, once_awnser.first, tree_edges);
    //cout << twice_awnser.first << " " << twice_awnser.second << '\n';

    cout << twice_awnser.second ;

    return 0;
}