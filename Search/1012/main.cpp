#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main () {
    int table_num;
    cin >> table_num;

    int anwser_array[table_num];

    for (int table_index = 0; table_index < table_num; table_index++){
        int table_horizon, table_vertical, fruit_num;
        cin >> table_horizon >> table_vertical >> fruit_num;

        // 안전한 2차원 vector 초기화
        vector<vector<int>> table(table_horizon, vector<int>(table_vertical, 0));

        for (int _=0; _ < fruit_num; _++){
            int fruit_x, fruit_y;
            cin >> fruit_x >> fruit_y;

            table[fruit_x][fruit_y] = 1;
        }

        int awnser = 0;

        for (int x = 0; x < table_horizon; x++){
            for (int y = 0; y < table_vertical; y++) {
                if (table[x][y] == 1){
                    awnser++;

                    stack<pair<int, int>> st;
                    st.push(pair<int, int>(x, y));
                    table[x][y] = 0;
                    

                    while(st.size() > 0) {
                        pair<int, int> node = st.top();
                        st.pop();

                        int central_x = node.first;
                        int central_y = node.second;

                        

                        if (central_x - 1 >= 0 && table[central_x - 1][central_y] == 1) {
                            st.push(pair<int, int>(central_x - 1, central_y));
                            table[central_x-1][central_y] = 0;
                        }

                        if (central_x + 1 < table_horizon && table[central_x + 1][central_y] == 1) {
                            st.push(pair<int, int>(central_x + 1, central_y));
                            table[central_x+1][central_y] = 0;
                        }
                        
                        if (central_y - 1 >= 0 && table[central_x][central_y-1] == 1) {
                            st.push(pair<int, int>(central_x, central_y-1));
                            table[central_x][central_y-1] = 0;
                        }

                        if (central_y + 1 < table_vertical && table[central_x][central_y+1] == 1) {
                            st.push(pair<int, int>(central_x, central_y+1));
                            table[central_x][central_y+1] = 0;
                        }

                    }
                }
            }
            
        }
        
        anwser_array[table_index] = awnser;
    }

    for (int table_index = 0; table_index < table_num; table_index++){
        cout << anwser_array[table_index] << endl;
    }



    return 0;
}