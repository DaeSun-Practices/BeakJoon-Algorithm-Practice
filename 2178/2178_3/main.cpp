#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main () {
    vector<vector<pair<bool, int>>> maze;

    int N, M;
    cin >> N >> M;

    for (int i=0; i<N; i++) {
        string row_string;
        cin >> row_string;

        vector<pair<bool, int>> row;

        for (int j=0; j<M; j++){
            if (row_string[j] == '1') {
                row.push_back(pair<bool, int>(true, -1));
            }
            else {
                row.push_back(pair<bool, int>(false, -1));
            }
        }
        maze.push_back(row);
    }

    queue<pair<int, int>> q;
    q.push(pair<int, int>(0,0));

    maze[0][0].first = false;
    maze[0][0].second = 1;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (q.size() > 0) {
        pair<int, int> current_node = q.front();  
        q.pop();

        int x = current_node.first;
        int y = current_node.second;
        int time_cost = maze[x][y].second;

        if (x == N-1 && y == M-1) {
            break;
        }

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny].first) {
                q.push(pair<int, int>(nx,ny));
                maze[nx][ny].first = false;
                maze[nx][ny].second = time_cost + 1;
            }
        }

    }

    cout << maze[N-1][M-1].second;

    return 0;
}