#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main () {
    int computer_num;
    cin >> computer_num;

    bool computers[computer_num];
    for (int i=1; i<computer_num; i++){
        computers[i] = true;

    } 
    computers[0] = false;

    stack<int> infection_stack;

    int line_num;
    cin >> line_num;
    vector<pair<int,int>> lan_line;

    for (int i=0; i<line_num; i++){
        int start_computer, end_computer;
        cin >> start_computer >> end_computer;
        lan_line.push_back(pair<int,int> (start_computer, end_computer));
    }

    int infected_num = 0;
    infection_stack.push(1);
    while (infection_stack.size() > 0){
        int target_computer = infection_stack.top();
        infection_stack.pop();


        for (int i=0; i<line_num; i++){
            pair<int,int> line = lan_line[i];
            if (line.first == target_computer && computers[line.second - 1]) {
                infection_stack.push(line.second);
                computers[line.second - 1] = false;
                infected_num++;
            }
            if (line.second == target_computer && computers[line.first - 1]) {
                infection_stack.push(line.first);
                computers[line.first - 1] = false;
                infected_num++;
            }
        }

    }

    cout << infected_num;


    return 0;
}