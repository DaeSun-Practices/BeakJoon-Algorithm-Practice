#include <bits/stdc++.h>

using namespace std;

int n;
int x;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<int> origin_vector;

    for (int _=0; _<n; _++){
        cin >> x;
        origin_vector.push_back(x);
    }

    //sort(origin_vector.begin(), origin_vector.end());

    int optimized_minus_index = 0;
    int optimized_plux_index = origin_vector.size() - 1;

    int optimized_current_diff = origin_vector[optimized_minus_index] + origin_vector[optimized_plux_index];
    int abs_optimized_current_diff = abs(optimized_current_diff);

    int current_minus_index = optimized_minus_index;
    int current_plux_index = optimized_plux_index;

    int current_diff = optimized_current_diff;
    int abs_current_diff = abs_optimized_current_diff;


    while (true) {
        //cout << current_diff << " " << abs_current_diff << " " << abs_optimized_current_diff << " " ;
        //cout << current_minus_index << " "  << current_plux_index << '\n';
        //cout << optimized_minus_index << " "  << optimized_plux_index << '\n';
        
        if (optimized_current_diff == 0) break;

        else if (optimized_current_diff > 0) {
            //cout << "try to reduce plus\n" ;
            current_plux_index --;

            current_diff = origin_vector[current_minus_index] + origin_vector[current_plux_index];
            abs_current_diff = abs(current_diff);

            if (abs_current_diff < abs_optimized_current_diff || optimized_current_diff < 0) {
                optimized_current_diff = current_diff;
                abs_optimized_current_diff = abs_current_diff;

                optimized_minus_index = current_minus_index;
                optimized_plux_index = current_plux_index;
            }

        }

        else if (optimized_current_diff < 0) {
            //cout << "try to reduce minus\n" ;
            current_minus_index ++;

            current_diff = origin_vector[current_minus_index] + origin_vector[current_plux_index];
            abs_current_diff = abs(current_diff);

            if (abs_current_diff < abs_optimized_current_diff || optimized_current_diff > 0) {
                optimized_current_diff = current_diff;
                abs_optimized_current_diff = abs_current_diff;

                optimized_minus_index = current_minus_index;
                optimized_plux_index = current_plux_index;
            }
        }

       

        if (current_minus_index >= current_plux_index) {
            break;
        }


        
    }


    cout << origin_vector[optimized_minus_index] << " " << origin_vector[optimized_plux_index];


    return 0;
}