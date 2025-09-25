#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>


using namespace std;



int main () {
    int horizon, vertical;
    cin >> vertical >> horizon;

    vector<vector<bool>> total_table;

    for (int _=0; _ < vertical; _++){
        string one_row;
        cin >> one_row;
        vector<bool> row_vec;

        for (int j=0; j < horizon; j++){
            if (one_row[j] == 'W') {
                row_vec.push_back(true);
            }
            else{
                row_vec.push_back(false);
            }
        }

        total_table.push_back(row_vec);

    }

    vector<vector<bool>> white_table;
    vector<vector<bool>> black_table;

    vector<bool> white_row;
    vector<bool> black_row;

    bool start_element = true;

    for (int j=0; j < 8; j++){
        white_row.push_back(start_element);
        black_row.push_back(!start_element);

        start_element = !start_element;
    }


    for (int i=0; i < 8; i++){
        if (i % 2 == 0){
            white_table.push_back(white_row);
            black_table.push_back(black_row);
        }
        else {
            white_table.push_back(black_row);
            black_table.push_back(white_row);
        }
    }

    vector<int> repaint_list; 
    for (int y=0; y <= vertical-8; y++){
        for (int x=0; x <= horizon-8; x++){
            int white_repaint_count = 0;
            int black_repaint_count = 0;


            for (int i=0; i < 8; i++){
                for (int j=0; j < 8; j++){
                    if (total_table[y+i][x+j] == white_table[i][j]){
                        white_repaint_count ++;
                    }
                    else {
                        black_repaint_count ++;
                    }
                }
            }

            int repaint_count = min(white_repaint_count, black_repaint_count);
            repaint_list.push_back(repaint_count);

            //cout<< repaint_count << endl;
        }
    }

    int awsner = repaint_list.back();
    repaint_list.pop_back();

    while (repaint_list.size() > 0 ){
        if (awsner > repaint_list.back()){
            awsner = repaint_list.back();
        }
        repaint_list.pop_back();
    }

    cout << awsner;
    /** 
    for (int i=0; i < 8; i++){
        for (int j=0; j < 8; j++){
            cout << white_table[i][j];
        }
        cout << endl;
    }

    for (int i=0; i < 8; i++){
        for (int j=0; j < 8; j++){
            cout << black_table[i][j];
        }
        cout << endl;
    }
    */


    return 0;
}