#include <bits/stdc++.h>

using namespace std;

int N, M, move_count;
vector<string> maze;

struct balls {
    pair<int, int> red;
    pair<int, int> blue;
};

struct node {
    int step;
    balls ball;
};

pair<balls, pair<bool, bool>> move_maze(balls ball, int direction){
    bool is_red = false;
    bool is_blue = false;
    balls current = ball;
    balls next_ball = ball;

    for (int _=0; _<move_count; _++){
        pair<int, int> red = current.red;
        pair<int, int> blue = current.blue;

        pair<int, int> next_red = red;
        pair<int, int> next_blue = blue;

        if (direction == 0){
            if (!is_red){
                int red_dd = red.second - 1;
                if (red_dd >=0) {
                    if (maze[red.first][red_dd] !='#'){
                        next_red.second = red_dd;
                    }
                }
            }

            if (!is_blue){
                int blue_dd = blue.second - 1;
                if (blue_dd >=0) {
                    if (maze[blue.first][blue_dd] !='#'){
                        next_blue.second = blue_dd;
                    }
                }
            }
        }
        else if (direction == 1){
            if (!is_red){
                int red_dd = red.second + 1;
                if (red_dd < M) {
                    if (maze[red.first][red_dd] !='#'){
                        next_red.second = red_dd;
                    }
                }
            }

            if (!is_blue){
                int blue_dd = blue.second + 1;
                if (blue_dd < M) {
                    if (maze[blue.first][blue_dd] !='#'){
                        next_blue.second = blue_dd;
                    }
                }
            }
        }
        else if (direction == 2){
            if (!is_red){
                int red_dd = red.first - 1;
                if (red_dd >= 0) {
                    if (maze[red_dd][red.second] !='#'){
                        next_red.first = red_dd;
                    }
                }
            }

            if (!is_blue){
                int blue_dd = blue.first - 1;
                if (blue_dd >= 0) {
                    if (maze[blue_dd][blue.second] !='#'){
                        next_blue.first = blue_dd;
                    }
                }
            }
        }
        else if (direction == 3){
            if (!is_red){
                int red_dd = red.first + 1;
                if (red_dd < N) {
                    if (maze[red_dd][red.second] !='#'){
                        next_red.first = red_dd;
                    }
                }
            }

            if (!is_blue){
                int blue_dd = blue.first + 1;
                if (blue_dd < N) {
                    if (maze[blue_dd][blue.second] !='#'){
                        next_blue.first = blue_dd;
                    }
                }
            }
        }

        


        next_ball.red = next_red;
        next_ball.blue = next_blue;

        if (!is_red){
            if (maze[next_red.first][next_red.second] == 'O'){
                is_red = true;
                next_red.first = -1;
                next_red.second = -1;

                next_ball.red = next_red;
            }
        }

        if (!is_blue){
            if (maze[next_blue.first][next_blue.second] == 'O'){
                is_blue = true;
                next_blue.first = -1;
                next_blue.second = -1;

                next_ball.blue = next_blue;
            }
        }

        if (next_red == next_blue) {
            if (next_blue == blue){
                next_ball.red=red;
            }
            else if (next_red == red){
                next_ball.blue=blue;
            }
        }

        


        current = next_ball;

        if (is_red || is_blue) break;
    }


    return pair<balls, pair<bool, bool>>(next_ball, pair<bool, bool>(is_red, is_blue));
}

void print_maze(balls ball){
    pair<int, int> red = ball.red;
    pair<int, int> blue = ball.blue;

    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (i == red.first && j == red.second){
                cout << 'R';
            }
            else if (i == blue.first && j == blue.second){
                cout << 'B';
            }
            else {
                cout << maze[i][j];
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    move_count = max(N,M);
    
    int x;

    balls init_balls;
    

    for (int i=0;i<N;i++){
        string maze_row;
        cin >> maze_row;

        for (int j=0; j<M; j++){
            if (maze_row[j] == 'B') {
                maze_row[j] = '.';
                init_balls.blue = pair<int, int>(i, j);
            }
            else if (maze_row[j] == 'R') {
                maze_row[j] = '.';
                init_balls.red = pair<int, int>(i, j);
            }
        }

        maze.push_back(maze_row);
    }
    node init_node;
    init_node.step = 0;
    init_node.ball = init_balls;

    queue<node> s;
    s.push(init_node);

    int opted_step = 11;

    /*
    print_maze(init_balls);
    pair<balls, pair<bool, bool>> result = move_maze(init_balls,0);
    balls next_ball = result.first;

    print_maze(next_ball);
    result = move_maze(next_ball,3);
    next_ball = result.first;

    print_maze(next_ball);
    result = move_maze(next_ball,1);
    next_ball = result.first;

    print_maze(next_ball);
    result = move_maze(next_ball,3);
    next_ball = result.first;

    print_maze(next_ball);
    result = move_maze(next_ball,2);
    next_ball = result.first;

    print_maze(next_ball);
    */
    
    while (!s.empty()){
        node current_node = s.front(); s.pop();
        int current_step = current_node.step;
        balls current_balls = current_node.ball;
        pair<int, int> current_red = current_balls.red;
        int red_y = current_red.first;
        int red_x = current_red.second;

        //cout << s.size() << '\n';
        //print_maze(current_balls);

        if (current_step < 10) {
            pair<balls, pair<bool, bool>> result;
            int next_step = current_step + 1;
            bool is_red;
            bool is_blue;
            balls next_ball;

            if (maze[red_y][red_x-1] != '#') {
                result = move_maze(current_balls,0);
                
                is_red = result.second.first;
                is_blue = result.second.second;

                if (is_red && !is_blue) {
                    opted_step = min(opted_step,next_step);
                }

                else if (!is_red && is_blue) {
                    //opted_step = min(opted_step,next_step);
                }

                else if (!is_red && !is_blue) {
                    next_ball = result.first;
                    node next_node;
                    next_node.ball = next_ball;
                    next_node.step = next_step;

                    s.push(next_node);
                }

            }
            if (maze[red_y][red_x+1] != '#') {
                result = move_maze(current_balls,1);
                
                is_red = result.second.first;
                is_blue = result.second.second;

                if (is_red && !is_blue) {
                    opted_step = min(opted_step,next_step);
                }

                else if (!is_red && is_blue) {
                    //opted_step = min(opted_step,next_step);
                }

                else if (!is_red && !is_blue) {
                    next_ball = result.first;
                    node next_node;
                    next_node.ball = next_ball;
                    next_node.step = next_step;

                    s.push(next_node);
                }

            }

            if (maze[red_y-1][red_x] != '#') {
                result = move_maze(current_balls,2);
                
                is_red = result.second.first;
                is_blue = result.second.second;

                if (is_red && !is_blue) {
                    opted_step = min(opted_step,next_step);
                }

                else if (!is_red && is_blue) {
                    //opted_step = min(opted_step,next_step);
                }

                else if (!is_red && !is_blue) {
                    next_ball = result.first;
                    node next_node;
                    next_node.ball = next_ball;
                    next_node.step = next_step;

                    s.push(next_node);
                }

            }

            if (maze[red_y+1][red_x] != '#') {
                result = move_maze(current_balls,3);
                
                is_red = result.second.first;
                is_blue = result.second.second;

                if (is_red && !is_blue) {
                    opted_step = min(opted_step,next_step);
                }

                else if (!is_red && is_blue) {
                    //opted_step = min(opted_step,next_step);
                }

                else if (!is_red && !is_blue) {
                    next_ball = result.first;
                    node next_node;
                    next_node.ball = next_ball;
                    next_node.step = next_step;

                    s.push(next_node);
                }

            }
        }
    }





    if (opted_step >= 11) {
        cout << -1;
    }
    else {
        cout << opted_step;
    }

    

    return 0;
}