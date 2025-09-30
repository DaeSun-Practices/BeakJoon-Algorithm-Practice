#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //queue를 이용한 BFS
    int start_num;
    cin >> start_num;
    queue<pair<int,int>> q;
    bool visited[start_num + 1] = {false, };

    q.push(pair<int,int>(start_num, 0));
    visited[start_num] = true;
    

    while (q.size() > 0){
        pair<int,int> current_node = q.front(); q.pop();

        int current_num = current_node.first;
        int current_cal_count = current_node.second;

        if (current_num == 1){
            cout << current_cal_count << '\n';
            break;
        }

        if (current_num % 3 == 0 && visited[current_num/3] == false){
            q.push(pair<int,int>(current_num/3, current_cal_count+1));
            visited[current_num/3]=true;
        }

        if (current_num % 2 == 0 && visited[current_num/2] == false){
            q.push(pair<int,int>(current_num/2, current_cal_count+1));
            visited[current_num/2]=true;
        }

        if (current_num > 1 && visited[current_num-1] == false){
            q.push(pair<int,int>(current_num-1, current_cal_count+1));
            visited[current_num-1]=true;
        }

    }

    return 0;
}