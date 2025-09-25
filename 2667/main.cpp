#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int main () {
    int N;
    cin >> N;

    vector<vector<bool>> table;

    for (int i=0; i<N; i++){
        string row_string;
        cin >> row_string;
        vector<bool> row;
        
        for (int j=0; j<N; j++){
            if (row_string[j] == '1') {
                row.push_back(true);
            }
            else {
                row.push_back(false);
            }
        }
        table.push_back(row);
    }

    vector<int> house_numbers;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++){

            if (table[i][j]) {
                int house_num = 0;
                queue<pair<int, int>> q;

                q.push(pair<int, int>(i,j));
                table[i][j] = false;
                house_num++;

                while (q.size() > 0) {
                    pair<int, int> current_node = q.front(); 
                    q.pop();

                    int x = current_node.first;
                    int y = current_node.second;

                    for (int cor=0; cor < 4; cor++){
                        int nx = x + dx[cor];
                        int ny = y + dy[cor];

                        if (nx >= 0 && ny >= 0 && nx < N && ny < N && table[nx][ny]) {
                            q.push(pair<int, int>(nx,ny));
                            table[nx][ny] = false;
                            house_num++;
                        }
                    }
                }

                house_numbers.push_back(house_num);
            }
        }
    }

    sort(house_numbers.begin(), house_numbers.end());

    cout << house_numbers.size() << endl;
    for (int  i=0; i < house_numbers.size(); i++){
        cout << house_numbers[i] << endl;
    }


    return 0;
}