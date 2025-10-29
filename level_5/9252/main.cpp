#include <bits/stdc++.h>

using namespace std;



struct Node {
    int a_index;
    int b_index;
    int max_length;
    string LCS;
};

queue<Node> q;

int max_lcs_length = 0;
string max_lcs; 

map <string, pair<int, int>> LCS_memory;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a_string, b_string;
    cin >> a_string;
    cin >> b_string;

    Node init_node;
    init_node.a_index = 0;
    init_node.b_index = 0;
    init_node.max_length = 0;
    init_node.LCS = "";

    
    q.push(init_node);


    while (!q.empty()) {
        Node current_node = q.front(); q.pop();
        int current_a_index = current_node.a_index;
        int current_b_index = current_node.b_index;
        int current_max_length = current_node.max_length;
        string current_LCS =  current_node.LCS;

        //cout << " " << current_a_index << " " << current_b_index << " " << current_LCS << '\n';

        if (current_max_length > max_lcs_length) {
            max_lcs_length = current_max_length;
            max_lcs = current_LCS;
        }
        

        if (current_a_index < a_string.size() && current_b_index < b_string.size()){
            char a_char_criteria = a_string[current_a_index];
            char b_char_criteria = b_string[current_b_index];


            for (int i=current_a_index; i<a_string.size(); i++){
                char current_a_char = a_string[i];

                if (current_a_char == b_char_criteria) {
                    int next_a_index = i+1;
                    int next_b_index = current_b_index+1;
                    string next_LCS = current_LCS + current_a_char;
                    
                    if (LCS_memory.find(next_LCS) == LCS_memory.end()){
                        Node next_node;
                        next_node.a_index = next_a_index;
                        next_node.b_index = next_b_index;
                        next_node.max_length = current_max_length + 1;
                        next_node.LCS = next_LCS;

                        q.push(next_node);

                        LCS_memory[next_LCS] = pair<int, int> (next_a_index, next_b_index);
                    }
                    else {
                        pair<int, int> map_indeces = LCS_memory[next_LCS];
                        int map_a_index = map_indeces.first;
                        int map_b_index = map_indeces.second;

                        if (!(next_a_index >= map_a_index && next_b_index >= map_b_index)){
                            Node next_node;
                            next_node.a_index = next_a_index;
                            next_node.b_index = next_b_index;
                            next_node.max_length = current_max_length + 1;
                            next_node.LCS = next_LCS;

                            q.push(next_node);

                            LCS_memory[next_LCS] = pair<int, int> (next_a_index, next_b_index);
                        }
                    }
                    

                    break;
                }
            }

            for (int i=current_b_index; i<b_string.size(); i++){
                char current_b_char = b_string[i];

                if (current_b_char == a_char_criteria) {
                    int next_a_index =  current_a_index + 1;
                    int next_b_index = i+1;
                    string next_LCS = current_LCS + current_b_char;

                    if (LCS_memory.find(next_LCS) == LCS_memory.end()){
                        Node next_node;
                        next_node.a_index = next_a_index;
                        next_node.b_index = next_b_index;
                        next_node.max_length = current_max_length + 1;
                        next_node.LCS = next_LCS;

                        q.push(next_node);

                        LCS_memory[next_LCS] = pair<int, int> (next_a_index, next_b_index);
                    }
                    else {
                        pair<int, int> map_indeces = LCS_memory[next_LCS];
                        int map_a_index = map_indeces.first;
                        int map_b_index = map_indeces.second;

                        if (!(next_a_index >= map_a_index && next_b_index >= map_b_index)){
                            Node next_node;
                            next_node.a_index = next_a_index;
                            next_node.b_index = next_b_index;
                            next_node.max_length = current_max_length + 1;
                            next_node.LCS = next_LCS;

                            q.push(next_node);
                            
                            LCS_memory[next_LCS] = pair<int, int> (next_a_index, next_b_index);
                        }
                    }


                    break;
                }
            }

        }
    }

    cout << max_lcs_length << '\n';
    if (max_lcs_length > 0)
        cout << max_lcs;

    return 0;
}