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

    int max_length = 0;

    for (int _=0;_<N;_++){
        string alphaet_string;
        cin >> alphaet_string;

        task_strings.push_back(alphaet_string);

        
        for (int i=0; i<alphaet_string.size(); i++){
            int digit = alphaet_string.size() - i;
            char alphabet = alphaet_string[i];

            if (number_map.find(alphabet) == number_map.end()){
                number_map[alphabet] = pow(10, digit);
            }
            else{
                number_map[alphabet] += pow(10, digit);
            }
        }
    }

    vector<pair<long long, char>> sort_vector;
    for (auto &kv: number_map){
        sort_vector.push_back(pair<long long, char>(kv.second, kv.first));
    }

    sort(sort_vector.begin(), sort_vector.end());

    unordered_map<char, int> transfer_map;
    int number = 9;

    for (int i = sort_vector.size()-1; i >= 0; i--) {
        auto current = sort_vector[i];
        transfer_map[current.second] = number--;
    }

    /*
    for (auto &kv: transfer_map){
        cout << kv.second << " " << kv.first << endl;
        //sort_vector.push_back(pair<long long, char>(kv.second, kv.first));
    }*/


    int awsner = 0;
    for (int i=0 ; i< task_strings.size(); i++){
        string current_string = task_strings[i];
        int current_number =  transfer_string(current_string, transfer_map);
        //cout << current_number << '\n';
        awsner += current_number;
    }

    cout << awsner;

    return 0;
}