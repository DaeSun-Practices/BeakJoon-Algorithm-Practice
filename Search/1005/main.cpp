#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

// DP 적용해라.
using namespace std;


int calculate_longest_time(int target_num, vector<pair<int,int>> rule_table, int rule_num, int building_times[]){
    int mine_time = building_times[target_num-1];

    vector<int> previous_building_numbers;
    for (int rule_index=0; rule_index < rule_num; rule_index++){
        if (rule_table[rule_index].second == target_num) {
            previous_building_numbers.push_back(rule_table[rule_index].first);
        }
    }

    if (previous_building_numbers.size() == 0){
        return mine_time;
    }
    
    else {
        vector<int> previous_times;
        for (int previous_index=0; previous_index < previous_building_numbers.size(); previous_index++) {
            int previous_building = previous_building_numbers[previous_index];
            int previous_time = calculate_longest_time(previous_building, rule_table, rule_num, building_times);

            previous_times.push_back(previous_time);
        }

        int max_previous_time = previous_times.back();
        previous_times.pop_back();

        while (previous_times.size() > 0) {
            int candidate_max_time = previous_times.back();
            max_previous_time = max(max_previous_time, candidate_max_time);
            previous_times.pop_back();
        }

        return mine_time + max_previous_time;
    }
}

int main () {
    int game_num;
    cin >> game_num;

    int total_awsnser [game_num];

    for (int game_index=0; game_index < game_num; game_index++){
        int building_num, rule_num;
        cin >> building_num >> rule_num;

        int building_times [building_num];
        for (int building_index=0; building_index < building_num; building_index++){
            cin >> building_times[building_index];
        }

        vector<pair<int,int>> rule_table;

        for (int rule_index=0; rule_index < rule_num; rule_index++){
            int start_building, end_building;
            cin >> start_building >> end_building;

            rule_table.push_back(pair<int,int>(start_building, end_building));
        }

        int target_building;
        cin >> target_building;

        int awser = calculate_longest_time(target_building, rule_table, rule_num, building_times); 
        total_awsnser[game_index] = awser;
    }


    for (int game_index=0; game_index < game_num; game_index++){
        cout << total_awsnser[game_index] << endl;
    
    } 


    return 0;
}