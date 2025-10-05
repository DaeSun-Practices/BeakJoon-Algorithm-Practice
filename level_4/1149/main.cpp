#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int red_costes[N];
    int green_costes[N];
    int blue_costes[N];

    for (int _=0; _<N; _++){
        int cost;
        cin >> cost;
        red_costes[_] = cost;
        cin >> cost;
        green_costes[_] = cost;
        cin >> cost;
        blue_costes[_] = cost;
    }

    int paint_cost[3][N];
    paint_cost[0][0] = red_costes[0];
    paint_cost[1][0] = green_costes[0];
    paint_cost[2][0] = blue_costes[0];

    for (int i=1; i<N; i++){
        paint_cost[0][i] = min(paint_cost[1][i-1], paint_cost[2][i-1]) +  red_costes[i];
        paint_cost[1][i] = min(paint_cost[0][i-1], paint_cost[2][i-1]) +  green_costes[i];
        paint_cost[2][i] = min(paint_cost[0][i-1], paint_cost[1][i-1]) +  blue_costes[i];
    }

    int min_cost =  paint_cost[0][N-1]; 
    min_cost = min(min_cost, paint_cost[1][N-1]);
    min_cost = min(min_cost, paint_cost[2][N-1]);

    cout << min_cost;
 

    return 0;
}