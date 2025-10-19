#include <bits/stdc++.h>

using namespace std;

int n;
int x;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<int> plus_vector;
    vector<int> minus_vector;
    bool has_zero = false;
    for (int _=0; _<n; _++){
        cin >> x;

        if (x > 0) plus_vector.push_back(x);
        else if (x < 0) minus_vector.push_back(x * (-1));
        else has_zero=true;
    }

    int min_water = 1000000001;
    sort(plus_vector.begin(), plus_vector.end());
    sort(minus_vector.begin(), minus_vector.end());

    for (int plus_element : plus_vector) cout << plus_element << " ";
    cout << '\n';
    for (int minus_element : minus_vector) cout << minus_element << " ";
    cout << '\n';

    int plus_n = plus_vector.size();
    int minus_n = minus_vector.size();

    for (int minus_element : minus_vector) {
        bool current_large = minus_element > plus_vector[plus_n/2];
        int left_index = 0;
        int right_index = plus_n;
        int pivot_index = plus_n/2;

        while (true) {

        }
    }



    if (plus_vector.size() >=2) 
        min_water = min(min_water, plus_vector[0] + plus_vector[1]);
    
    if (minus_n >=2) 
        min_water = min(min_water, (minus_vector[0] + minus_vector[1]) );

    if (plus_vector.size() >=1 && has_zero) 
        min_water = min(min_water, plus_vector[0]);
    
    if (minus_n >=1 && has_zero) 
        min_water = min(min_water, minus_vector[0] );

    cout << min_water;



    return 0;
}