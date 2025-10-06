#include <bits/stdc++.h>

using namespace std;

void pre_order(int value_index, pair<int, int> nodes[]){
    char value = 'A' + value_index;
    cout << value;

    int left_index, right_index;
    left_index = nodes[value_index].first;
    right_index = nodes[value_index].second;

    if (left_index != -1) {
        pre_order(left_index, nodes);
    }
    if (right_index != -1) {
        pre_order(right_index, nodes);
    }
}

void middle_order(int value_index, pair<int, int> nodes[]){
    char value = 'A' + value_index;
    

    int left_index, right_index;
    left_index = nodes[value_index].first;
    right_index = nodes[value_index].second;

    if (left_index != -1) {
        middle_order(left_index, nodes);
    }
    
    cout << value;

    if (right_index != -1) {
        middle_order(right_index, nodes);
    }
}

void post_order(int value_index, pair<int, int> nodes[]){
    char value = 'A' + value_index;
    

    int left_index, right_index;
    left_index = nodes[value_index].first;
    right_index = nodes[value_index].second;

    if (left_index != -1) {
        post_order(left_index, nodes);
    }
    
    if (right_index != -1) {
        post_order(right_index, nodes);
    }

    cout << value;
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    pair<int, int> nodes[N];

    for (int i=0; i<N; i++){
        char value, left_node, right_node;
        cin >> value >> left_node >> right_node;

        int value_index = value - 'A';
        int left_index = -1;
        if (left_node != '.'){
            left_index = left_node - 'A';
        }
        int right_index = -1;
        if (right_node != '.'){
            right_index = right_node - 'A';
        }

        nodes[value_index] = pair<int, int> (left_index, right_index);
    }

    pre_order(0, nodes);
    cout << '\n';
    middle_order(0, nodes);
    cout << '\n';
    post_order(0, nodes);




    return 0;
}