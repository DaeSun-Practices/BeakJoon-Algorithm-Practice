#include <bits/stdc++.h>
using namespace std;

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

    vector<bool> reached(V+1, false);
    int reached_edge_num = 0;
    int total_cost = 0;

    for (pair<int, pair<int, int>> edge : edges){
        int cost = edge.first;
        int node1 = edge.second.first;
        int node2 = edge.second.second;

        if (reached[node1] && reached[node2]) {
            continue;
        }
        else {
            reached[node1] = true;
            reached[node2] = true;
            reached_edge_num ++;
            total_cost += cost;
        }

        if (reached_edge_num >= V-1) break;
    }

    cout << total_cost;
    
    return 0;
}
