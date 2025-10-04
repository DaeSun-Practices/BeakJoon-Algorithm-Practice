#include <bits/stdc++.h>

using namespace std;


int transfer_string(string target_string, unordered_map<char, int> number_map){
    int transfered_int = 0;

    for (int i=0; i<target_string.size(); i++){
        transfered_int *= 10;
        char current_char = target_string[i];
        transfered_int += number_map[current_char];
    }


    return transfered_int;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> task_strings;
    unordered_map<char, int> number_map;
    set<string> string_set;

    int max_length = 0;

    for (int _=0;_<N;_++){
        string alphaet_string;
        cin >> alphaet_string;

        task_strings.push_back(alphaet_string);
        string_set.insert(alphaet_string);

        int string_length = alphaet_string.size();
        max_length = max(max_length, string_length);
    }


    int number = 9;

    for (int target_length=max_length; target_length>0; target_length--){

        for (auto task_string: string_set){
            cout << task_string << " " << target_length << endl << endl;

            if (task_string.size() == target_length){
                char first_char = task_string[0];
                if (number_map.find(first_char) == number_map.end()){
                    number_map[first_char] = number;
                    number--;
                }

                string new_sting = task_string.substr(1, task_string.size()-1);
                cout << task_string << " " << new_sting << endl << endl;

                string_set.erase(task_string);
                string_set.insert(new_sting);
            }
        }
    }

    int awnser = 0;
    for (auto task_string: task_strings){
        int current = transfer_string(task_string, number_map);
        cout << current << '\n';
        awnser += current;
    }
   
    cout << awnser;

    return 0;
}