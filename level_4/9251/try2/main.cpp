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

    lcs_node init_node;
    init_node.lcs = "";
    init_node.start_1_index = 0;
    init_node.start_2_index = 0;
    q.push(init_node);


    int max_lcs_num = 0;

    map<string, pair<int, int>> node_memory;

    while(!q.empty()){
        lcs_node current_node = q.front(); q.pop();
        string lcs = current_node.lcs;
        int index1 = current_node.start_1_index;
        int index2 = current_node.start_2_index;

        //cout << lcs << " " << index1 << " " << index2 << '\n';

        int lcs_size = lcs.size();
        max_lcs_num = max(max_lcs_num,lcs_size);

        bool is_1_done = false;
        for (int i=index1; i<string_1.size(); i++){
            char char1 = string_1[i];

            for (int j=index2; j<string_2.size(); j++){
                char char2 = string_2[j];

                if (char1 == char2){
                    string new_lcs = lcs + char1;
                    int new_start_1_index = i+1;
                    int new_start_2_index = j+1;

                    if (node_memory.find(new_lcs) == node_memory.end()){
                        node_memory[new_lcs] = pair<int, int> (new_start_1_index, new_start_2_index);

                        lcs_node new_node;
                        new_node.lcs = new_lcs;
                        new_node.start_1_index = new_start_1_index;
                        new_node.start_2_index = new_start_2_index;

                        q.push(new_node);

                    }
                    else {
                        pair<int, int> last_memory = node_memory[new_lcs];
                        if (!(last_memory.first <= new_start_1_index || last_memory.second <= new_start_2_index)) {
                            node_memory[new_lcs] = pair<int, int> (new_start_1_index, new_start_2_index);

                            lcs_node new_node;
                            new_node.lcs = new_lcs;
                            new_node.start_1_index = new_start_1_index;
                            new_node.start_2_index = new_start_2_index;

                            q.push(new_node);
                        }
                    }

                    
                    is_1_done = true;
                    break;
                }
            }
            if (is_1_done) break;
        }


        bool is_2_done = false;
        for (int j=index2; j<string_2.size(); j++){
            char char2 = string_2[j];

            for (int i=index1; i<string_1.size(); i++){
                char char1 = string_1[i];

                if (char1 == char2){
                    string new_lcs = lcs + char2;
                    int new_start_1_index = i+1;
                    int new_start_2_index = j+1;

                    if (node_memory.find(new_lcs) == node_memory.end()){
                        node_memory[new_lcs] = pair<int, int> (new_start_1_index, new_start_2_index);

                        lcs_node new_node;
                        new_node.lcs = new_lcs;
                        new_node.start_1_index = new_start_1_index;
                        new_node.start_2_index = new_start_2_index;

                        q.push(new_node);

                    }
                    else {
                        pair<int, int> last_memory = node_memory[new_lcs];
                        if (!(last_memory.first <= new_start_1_index || last_memory.second <= new_start_2_index)) {
                            node_memory[new_lcs] = pair<int, int> (new_start_1_index, new_start_2_index);

                            lcs_node new_node;
                            new_node.lcs = new_lcs;
                            new_node.start_1_index = new_start_1_index;
                            new_node.start_2_index = new_start_2_index;

                            q.push(new_node);
                        }
                    }

                    is_2_done = true;
                    break;
                }
            }
            if (is_2_done) break;
        }
    }

    cout << max_lcs_num ;

    return 0;
}