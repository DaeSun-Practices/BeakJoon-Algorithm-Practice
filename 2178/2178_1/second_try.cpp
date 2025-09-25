#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main () {
    int height, horizon;
    cin >> height >> horizon;

    vector<vector<bool>> maze;
    vector<vector<int>> time_cost;

    for (int i=0; i < height; i++){
        vector<bool> row;
        vector<int> cost_row;

        string input_string;
        cin >> input_string;

        for (int j=0; j<horizon; j++){
            if (input_string[j] == '1') {
                row.push_back(true);
            }
            else {
                row.push_back(false);
            }

            cost_row.push_back(-1);
        }

        maze.push_back(row);
        time_cost.push_back(cost_row);
    }

    /** 
    for (int i=0; i < height; i++){
        for (int j=0; j<horizon; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }

    for (int i=0; i < height; i++){
        for (int j=0; j<horizon; j++){
            cout << time_cost[i][j];
        }
        cout << endl;
    }
    */
    

    queue<pair<int, int>> st;
    st.push(pair<int, int> (0,0));
    maze[0][0] = false;
    time_cost[0][0] = 1;

    while (st.size() > 0){
        pair<int, int> position = st.back();
        st.pop();

        int y = position.first;
        int x = position.second;
        int current_time = time_cost[y][x];

        maze[y][x] = false;

        if ((x + 1 < horizon) && maze[y][x + 1]) {
            
            
            if (time_cost[y][x + 1] == -1) {
                time_cost[y][x + 1] = current_time + 1;
            }
            else {
                time_cost[y][x + 1] = min(time_cost[y][x + 1], current_time + 1);
            }
            

            st.push(pair<int, int> (y,x + 1));
        }

        if ((y + 1 < height) && maze[y+1][x]) {
            if (time_cost[y+1][x] == -1) {
                time_cost[y+1][x] = current_time + 1;
            }
            else {
                time_cost[y+1][x]= min(time_cost[y+1][x], current_time + 1);
            }

            st.push(pair<int, int> (y+1,x));
        }

        if ((x - 1 >= 0) && maze[y][x - 1]) {
            if (time_cost[y][x - 1] == -1) {
                time_cost[y][x - 1] = current_time + 1;
            }
            else {
                time_cost[y][x - 1] = min(time_cost[y][x - 1], current_time + 1);
            }

            st.push(pair<int, int> (y,x - 1));
        }

        if ((y - 1 >= 0) && maze[y-1][x]) {
            if (time_cost[y-1][x] == -1) {
                time_cost[y-1][x] = current_time + 1;
            }
            else {
                time_cost[y-1][x] = min(time_cost[y-1][x], current_time + 1);
            }

            st.push(pair<int, int> (y-1,x));
        }


    }
    
    cout << time_cost[height-1][horizon-1];

    return 0;
}
