#include <bits/stdc++.h>

using namespace std;


struct lcs_node {
    string lcs;
    int start_1_index;
    int start_2_index;
};


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string string_1;
    string string_2;

    cin >> string_1;
    cin >> string_2;

    // to initial
    queue<lcs_node> q;
    int min_string_1_index = 1002;
    int min_string_2_index = 1002;

    bool init_done = false;
    int max_lcs = 0;

    for (int i=0; i<string_1.size(); i++){
        char char_1 = string_1[i];
        for (int j=0; j<string_2.size(); j++){
            char char_2 = string_2[j];

            if (char_1 == char_2){
                lcs_node init_lcs;
                init_lcs.lcs = char_1;
                init_lcs.start_1_index = i+1;
                init_lcs.start_2_index = j+1;

                q.push(init_lcs);

                if (min_string_1_index >  i) min_string_1_index = i;
                if (min_string_2_index >  j) min_string_2_index = j;

                max_lcs = 1;
            }

            if (min_string_1_index < i && min_string_2_index < j){
                init_done = true;
                break;
            }
        }

        if (init_done) break;
    }

    int max_lcs = 0;

    while (!q.empty()){
        lcs_node current_node = q.front(); q.pop();
        string lcs = current_node.lcs;
        int index_1 = current_node.start_1_index;
        int index_2 = current_node.start_2_index;

        bool is_1_done = false;
        
        for (int i=index_1; i<string_1.size(); i++){
            char char1 = string_1[i];
            for (int j=index_2; j<string_2.size(); j++){
                char char2 = string_2[j];

                if (char1 == char2){
                    lcs_node init_lcs;
                    init_lcs.lcs = lcs + char1;
                    init_lcs.start_1_index = i+1;
                    init_lcs.start_2_index = j+1;

                    q.push(init_lcs);
                }

                if (min_string_1_index < i && min_string_2_index < j){
                    init_done = true;
                    break;
                }
            }
        }
        
    }


    return 0;
}