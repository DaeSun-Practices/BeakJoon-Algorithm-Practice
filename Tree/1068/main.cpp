#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool is_valid_node[n];

    vector<int> parents;
    for (int _=0;_<n;_++){
        int x;
        cin >> x;

        is_valid_node[_] = true;
        parents.push_back(x);
    }

    int delete_node;
    cin >> delete_node;

    queue<int>q;
    q.push(delete_node);
    is_valid_node[delete_node] = false;

    while (!q.empty()) {
        int current_index = q.front(); q.pop();

        for (int i=0; i< n; i++){
            if (parents[i]==current_index){
                q.push(i);
                is_valid_node[i] = false;
                parents[i] = -1;
            }
        }
    }

    int awnser = 0;
    for (int i=0;i<n;i++){
        if(is_valid_node[i]){
            bool is_leaf = true;

            for (int j=0; j<n;j++){
                if (is_valid_node[j] && parents[j]==i){
                    is_leaf = false;
                    break;
                }
            }

            if (is_leaf) awnser++;
        }
    }

    /*
    for (int i=0; i<n; i++){
        cout << is_valid_node[i] << " ";
    }
    cout << '\n';
    */
   
    cout << awnser;

    return 0;
}