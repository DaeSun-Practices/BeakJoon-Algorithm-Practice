#include <bits/stdc++.h>
using namespace std;

int N;
int awnser;



pair<int, int> dfs (int initial_index, int n, vector<vector<pair<int, int>>> edge_cost_array){
    vector<int> node_cost_vector(n+1, -1);
    node_cost_vector[initial_index] = 0;


    stack<int>s;
    s.push(initial_index);

    int half_cost=0, half_index=initial_index;

    while (!s.empty()){
        int current_index = s.top(); s.pop();
        int current_cost = node_cost_vector[current_index];

        if (current_cost > half_cost){
            half_cost = current_cost;
            half_index = current_index;
        }

        vector<pair<int, int>> edges = edge_cost_array[current_index];
        sort(edges.begin(), edges.end(), greater());

        for (pair<int, int> edge : edges){
            int next_index = edge.second;
            int next_cost = edge.first;
            
            if (node_cost_vector[next_index] == -1){

                node_cost_vector[next_index] = current_cost + next_cost;

                s.push(next_index);
            }
            

        }

        //free(visited);
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

    
    for (int i=0; i<=N; i++) edge_cost_array.push_back(vector<pair<int, int>>{});

    for (int i=1; i<=N; i++){
        cin >> current_node;

        while (true) {
            cin >> next_node;
            if (next_node == -1 ) break;
            cin >> edge_cost;

            edge_cost_array[current_node].push_back(pair<int, int>(edge_cost, next_node));
            edge_cost_array[next_node].push_back(pair<int, int>(edge_cost, current_node));
        }
    }
    
    pair <int, int> half_result =  dfs(1, N, edge_cost_array);
    //cout << half_result.first << " " << half_result.second << "\n";
    
    pair <int, int> total_result =  dfs(half_result.first, N, edge_cost_array);
    cout << total_result.second;

    
    return 0;
}