#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> adj(N+1); // 인접 리스트

    for (int i = 0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(N+1, 0);
    vector<bool> visited(N+1, false);

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()){
        int cur = q.front(); q.pop();

        for (int nxt : adj[cur]) {
            if (!visited[nxt]) {
                visited[nxt] = true;
                parent[nxt] = cur;   // 부모 기록
                q.push(nxt);
            }
        }
    }

    for (int i=2; i<=N; i++){
        cout << parent[i] << '\n';
    }

    return 0;
}