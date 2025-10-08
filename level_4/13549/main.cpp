#include <bits/stdc++.h>

using namespace std;



int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> step_memory(1000001, -1);

    queue<int> q;
    q.push(N);
    step_memory[N] = 0;

    while (!q.empty()) {
        int current_position = q.front(); q.pop();
        int crruent_step = step_memory[current_position];

        if (current_position != K){
            if (current_position > 0){
                int back_position = current_position - 1;
                int back_step = crruent_step + 1;

                if ( step_memory[back_position] == -1 || back_step < step_memory[back_position]){
                    q.push(back_position);
                    step_memory[back_position] = back_step;
                }
            }

            if (current_position < 100000) {
                int front_position = current_position + 1;
                int front_step = crruent_step + 1;

                if ( step_memory[front_position] == -1 || front_step < step_memory[front_position]){
                    q.push(front_position);
                    step_memory[front_position] = front_step;
                }
            }

            if (current_position <= 50000) {
                int double_position = current_position * 2;
                int double_step = crruent_step;

                if ( step_memory[double_position] == -1 || double_step < step_memory[double_position]){
                    q.push(double_position);
                    step_memory[double_position] = double_step;
                }
            }
        }

        
        
    }

    cout << step_memory[K];
    return 0;
}