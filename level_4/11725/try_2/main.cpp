#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int tree_node_array[N+1];
    bool visited[N+1] = { false };

    vector<pair<int, int>> edges;

    for (int _=0; _ < N-1; _++){
        int src_node, trg_node;
        cin >> src_node >> trg_node;
        edges.push_back(pair<int, int>(trg_node, src_node));
        /*
        if (src_node > trg_node){
            edges.push_back(pair<int, int>(trg_node, src_node));
        }
        else {
            edges.push_back(pair<int, int>(src_node, trg_node));
        }
            */
    }

    //sort(edges.begin(), edges.end());

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()){
        int current_node = q.front(); q.pop();
        vector<pair<int, int>> servived_edges;

        for (int i=0; i < edges.size(); i++){
            pair<int, int> edge = edges[i];
            if (edge.first==current_node && !visited[edge.second] ){
                q.push(edge.second);
                visited[edge.second] = true;
                tree_node_array[edge.second] = current_node;
                
            }
            else if (edge.second==current_node && !visited[edge.first] ){
                q.push(edge.first);
                visited[edge.first] = true;
                tree_node_array[edge.first] = current_node;

            }
            else {
                servived_edges.push_back(edge);
            }
        }
        edges = servived_edges;


    }



    for (int i=2; i<=N; i++){
        cout << tree_node_array[i] << '\n';
    }

    return 0;
}