#include <bits/stdc++.h>
using namespace std;

int N;
int awnser;

struct node {
    int node_index;
    int cost;
    vector<bool> visited;
};


pair<int, int> dfs (int initial_index, int n, vector<vector<pair<int, int>>> edge_cost_array){
    vector<bool> initial_visited;
    for (int i=0; i<n+1; i++) initial_visited.push_back(false);

    initial_visited[initial_index] = true;

    node initial_node;
    initial_node.node_index = initial_index;
    initial_node.cost = 0;
    initial_node.visited = initial_visited;

    stack<node>s;
    s.push(initial_node);

    int half_cost=0, half_index=initial_index;

    while (!s.empty()){
        node current_node = s.top(); s.pop();

        int current_index = current_node.node_index;
        int current_cost = current_node.cost;
        vector<bool> visited = current_node.visited;

        if (current_cost > half_cost){
            half_cost = current_cost;
            half_index = current_index;
        }

        vector<pair<int, int>> edges = edge_cost_array[current_index];
        sort(edges.begin(), edges.end(), greater());

        for (pair<int, int> edge : edges){
            int next_index = edge.second;
            int next_cost = edge.first;
            
            if (!visited[next_index]){
                node next_node;
                next_node.node_index = next_index;
                next_node.cost = current_cost + next_cost;
                next_node.visited = visited;
                next_node.visited[next_index] = true;

                s.push(next_node);
            }

        }
    }

    return pair<int, int> (half_index, half_cost);

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<vector<pair<int, int>>> edge_cost_array;
    
    int current_node;
    int next_node;
    int edge_cost;

    
    edge_cost_array.push_back(vector<pair<int, int>>{});
    for (int i=1; i<=N; i++){
        cin >> current_node;
        vector<pair<int, int>> edges;
        
        while (true) {
            cin >> next_node;
            if (next_node == -1 ) break;
            cin >> edge_cost;

            edges.push_back(pair<int, int>(edge_cost, next_node));
        }
        edge_cost_array.push_back(edges);
    }
    
    pair <int, int> half_result =  dfs(1, N, edge_cost_array);
    //cout << half_result.first << " " << half_result.second << "\n";
    
    pair <int, int> total_result =  dfs(half_result.first, N, edge_cost_array);
    cout << total_result.second;

    


    return 0;
}
