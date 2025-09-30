#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool my_set[20] = {false,};

    int command_num;
    cin >> command_num;

    //vector<bool> output_vector;

    for (int command_idx=0; command_idx<command_num; command_idx++){
        string command;
        cin >> command;

        if (command == "add"){
            int command_number;
            cin >> command_number;
            my_set[command_number-1]=true;
        }
        else if (command == "remove"){
            int command_number;
            cin >> command_number;
            my_set[command_number-1]=false;
        }
        else if (command == "check"){
            int command_number;
            cin >> command_number;
            
            cout << my_set[command_number-1] << endl;

            /*
            if (my_set[command_number-1]){
                output_vector.push_back(true);
            }
            else {
                output_vector.push_back(false);
            }
            */
            
        }
        else if (command == "toggle"){
            int command_number;
            cin >> command_number;
            
            if (my_set[command_number-1]){
                my_set[command_number-1] = false;
            }
            else {
                my_set[command_number-1] = true;
            }
            
        }
        else if (command == "all"){
            for (int num_idx=0; num_idx<20; num_idx++){
                my_set[num_idx] = true;
            }
        }
        else if (command == "empty"){
           for (int num_idx=0; num_idx<20; num_idx++){
                my_set[num_idx] = false;
            }
        }
    }

    /*
    for (int output_idx=0; output_idx < output_vector.size(); output_idx++){
        cout << output_vector[output_idx] << endl;
    }
    */


    return 0;
}