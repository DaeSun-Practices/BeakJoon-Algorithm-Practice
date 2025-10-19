#include <bits/stdc++.h>
using namespace std;


vector<int> parents;
vector<bool> visited;

int get_root_index (int start_index){
    if (start_index == parents[start_index]) 
        return start_index;
    return parents[start_index] = get_root_index(parents[start_index]);

}

bool are_they_same_tree (int a, int b){
    int a_parent = get_root_index(a);
    int b_parent = get_root_index(b);

    return a_parent == b_parent;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, E;
    cin >> V >> E;

    vector<pair<int, pair<int, int>>> edges;

    
    int x, y, z;
    for (int _=0; _<E; _++){
        cin >> x >> y >> z;

        //cout << x << y << z;

        edges.push_back(pair<int, pair<int, int>>(z, pair<int, int>(x, y)));
    }

    sort(edges.begin(), edges.end());


    for (int i=0; i<=V; i++) {
        parents.push_back(i);
        //visited.push_back(false);
    }


    int reached_edge_num = 0;
    int total_cost = 0;

    for (pair<int, pair<int, int>> edge : edges){
        int cost = edge.first;
        int node1 = edge.second.first;
        int node2 = edge.second.second;

        //if (visited[node1] && visited[node2]) continue;

        int a_parent = get_root_index(node1);
        int b_parent = get_root_index(node2);


        if (a_parent != b_parent){
            parents[a_parent] = b_parent;

            //visited[node1] = true;
            //visited[node2] = true;

            reached_edge_num ++;
            total_cost += cost;
        }

        if (reached_edge_num >= V-1) break;
    }

    cout << total_cost;
    
    return 0;
}
