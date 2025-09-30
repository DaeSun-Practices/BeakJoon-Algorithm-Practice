#include <iostream>
#include <set>
#include <cstring>
#include <vector>

using namespace std;

int main () {
    set<int> s;

    int command_num;
    cin >> command_num;

    vector<bool> output_vector;

    for (int command_idx=0; command_idx < command_num; command_idx++){
        /** 
        string command_type;
        
        cin >> command_type >> input_number;
        */

        string command_type;
        cin >> command_type;
        int input_number;
        

        if (command_type == "add"){
            cin >> input_number;
            if (s.find(input_number) == s.end()){
                s.insert(input_number);
            }
            else{
            }
        }
        
        else if (command_type == "check"){
            cin >> input_number;
            if (s.find(input_number) == s.end()){
                //cout << 0 << endl;
                output_vector.push_back(false);
            }
            else{
                //cout << 1 << endl;
                output_vector.push_back(true);
            }
        }
        else if (command_type == "remove"){
            cin >> input_number;
            if (s.find(input_number) == s.end()){
            }
            else{
                s.erase(input_number);
            }
        }
        else if (command_type == "toggle"){
            cin >> input_number;
            if (s.find(input_number) == s.end()){
                s.insert(input_number);
            }
            else{
                s.erase(input_number);
            }
        }

        else if (command_type == "all"){
            s = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        }

        else if (command_type == "empty"){
            s = {};
        }
    }


    for (int output_idx=0; output_idx < output_vector.size(); output_idx++){
        cout << output_vector[output_idx] << endl;
    }

    return 0;
}