#include <iostream>
#include <map>
#include <string>
#include <cstring>

using namespace std;

int main () {
    int N, M;
    cin >> N >> M;

    string find_by_number[N];
    map<string, int> find_by_string;

    for (int index=1; index <= N; index++){
        string name;
        cin >> name;

        //find_by_number.insert({index, name});
        find_by_number[index-1] = name;
        find_by_string.insert({name, index});
    }

    for (int i=0; i < M; i++){
        string problem_input;
        cin >> problem_input;

        try {
            int number_index = stoi(problem_input);
            cout << find_by_number[number_index-1] << '\n';
        }
        catch(...){
            cout << find_by_string[problem_input] << '\n';
        }
    }

    return 0;
}