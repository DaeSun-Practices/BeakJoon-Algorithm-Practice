#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main () {
    int N, K;
    cin >> N >> K;
    
    map<int, int> time_road;
    queue<int> q;


    time_road[N] = 0;
    q.push(N);


    while (true) {
        int current = q.front(); q.pop();
        int time_cost = time_road[current];

        if (current == K){
            break;
        }


        int walk1 = current-1;
        // 인덱스 범위 설정을 잘하자!
        if (walk1 >=0 && time_road.find(walk1) == time_road.end()){
            time_road[walk1] = time_cost+1;
            q.push(walk1);
        }

        int walk2 = current+1;
        if (walk2 <= 100000 && time_road.find(walk2) == time_road.end()){
            time_road[walk2] = time_cost+1;
            q.push(walk2);
        }

        int walk3 = current*2;
        if (walk3 <= 100000 && time_road.find(walk3) == time_road.end()){
            time_road[walk3] = time_cost+1;
            q.push(walk3);
        }

        
    }


    cout << time_road[K];


    return 0;
}