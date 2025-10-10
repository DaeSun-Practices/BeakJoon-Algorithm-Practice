#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int vertical_costs[n];
    int horizental_costs[n];

    int parents[n];
    for (int i=0;i<n;i++){
        int x;
        cin >> x;

        vertical_costs[i] = 0;
        horizental_costs[i] = 0;
        parents[i] = x;
    }

    
    queue<int>q;
    q.push(0);

    while (!q.empty()) {
        int current_index = q.front(); q.pop();
        int current_vertical_cost = vertical_costs[current_index];
        int current_horizental_cost = 0;

        for (int i=0;i<n;i++){
            if (parents[i] == current_index){
                current_horizental_cost++;
            }
        }

        for (int i=0;i<n;i++){
            if (parents[i] == current_index){
                vertical_costs[i] = current_vertical_cost+1;
                horizental_costs[i] = current_horizental_cost;
                q.push(i);
                
            }
        }

        //horizental_costs[current_index] = current_horizental_cost;
    }


    
    for (int i=0;i<n;i++){
        int current_vertical_cost = vertical_costs[i];
        cout << current_vertical_cost << " ";
    }
    cout << '\n';
    for (int i=0;i<n;i++){
        int current_vertical_cost = horizental_costs[i];
        cout << current_vertical_cost << " ";
    }

    
    int max_cost = 0;
    for (int i=0;i<n;i++){
        max_cost = max(max_cost, vertical_costs[i] + horizental_costs[i]);
    }
    
    cout << max_cost;

    return 0;
}