#include <bits/stdc++.h>

using namespace std;


int transfer_string(string target_string, vector<char> char_list, vector<int> number_list){
    int transfered_int = 0;

    for (int i=0; i<target_string.size(); i++){
        transfered_int *= 10;
        char current_char = target_string[i];

        for (int j=0; j<char_list.size(); j++){
            if (char_list[j] == current_char) {
                transfered_int += number_list[j];

                break;
            }   
        }
    }


    return transfered_int;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> task_strings;
    set<char> char_set;
    vector<char> char_list;

    for (int _=0;_<N;_++){
        string alphaet_string;
        cin >> alphaet_string;
    
        for (int i=0; i < alphaet_string.size(); i++){
            if (char_set.find(alphaet_string[i]) == char_set.end()){
                char_set.insert(alphaet_string[i]);
                char_list.push_back(alphaet_string[i]);
            }
        }

        task_strings.push_back(alphaet_string);
    }

    vector<int> number_list;
    for (int i=0; i< char_list.size(); i++){
        number_list.push_back(9-i);
    }

    sort(number_list.begin(), number_list.end());

    int awsnser = 0;
    do {
        int current = 0;
        for (int i=0; i<N;i++){
            int number = transfer_string(task_strings[i], char_list, number_list);
            current += number;
        }
        awsnser = max(awsnser, current);

    } while (next_permutation(number_list.begin(),number_list.end()));

    cout << awsnser;

    return 0;
}