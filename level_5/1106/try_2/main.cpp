#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long cummlated_cost;
    long long cummlated_people;
    int last_index;
};

bool opt_compare(pair<int, int>a, pair<int, int>b){
    float f_c_a = a.first * 1.0; 
    float f_c_b = b.first * 1.0; 

    return a.second / f_c_a > b.second / f_c_b;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N;
    cin >> C >> N;

    

    vector<pair<int, int>> cost_peoples;

    int cost, people;
    for (int _=0; _<N; _++){
        cin >> cost >> people;
        
        bool is_valid = true;
        vector<int> delete_indeces;

        int max_index = cost_peoples.size();
        
        for (int i=0; i<max_index; i++){
            if (cost_peoples[i].first >= cost && cost_peoples[i].second <= people){
                cost_peoples.erase(cost_peoples.begin() + i);
                i--; max_index--;
            }

            else if (cost_peoples[i].first <= cost && cost_peoples[i].second >= people)
                is_valid = false;
        }


        if (is_valid)
            cost_peoples.push_back(pair<int, int>(cost, people));
    }

    sort(cost_peoples.begin(), cost_peoples.end(), opt_compare);
    
    N = cost_peoples.size();
    /*
    for (int i=0; i<N; i++){
        cout << cost_peoples[i].first << " " << cost_peoples[i].second << endl;
    }
    */
    

    long long max_cost = LLONG_MAX;
    Node init_node;
    init_node.cummlated_cost = 0;
    init_node.cummlated_people = 0;
    init_node.last_index = 0;

    stack<Node> q;
    q.push(init_node);
    priority_queue<int> satisfied_q;

    vector<long long> max_cost_vector (C+1001, LLONG_MAX);

    while (!q.empty()){
        Node current_node = q.top(); q.pop();
        long long current_cummlated_cost = current_node.cummlated_cost;
        long long current_cummlated_people = current_node.cummlated_people;
        int current_last_index = current_node.last_index;

        max_cost_vector[current_cummlated_people] = min(current_cummlated_cost, max_cost_vector[current_cummlated_people]);

        if (current_cummlated_people >=  C){
            max_cost = min(max_cost, current_cummlated_cost);
        }

        else{
            for (int i=current_last_index; i<N; i++){
                Node next_node;
                long long next_cost = current_cummlated_cost + cost_peoples[i].first;
                long long next_people = current_cummlated_people + cost_peoples[i].second;

                //if (next_people > C) continue;

                if (max_cost_vector[next_people] <= next_cost) continue;


                next_node.last_index = i;
                next_node.cummlated_cost = next_cost;
                next_node.cummlated_people = next_people;

                q.push(next_node);
            }
        }
        
    }

    cout << max_cost;
    



    return 0;
}