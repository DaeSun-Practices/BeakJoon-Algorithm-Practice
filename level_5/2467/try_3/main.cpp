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

    int optid_diff = 2000000001;
    int opt_plus, opt_minus;
    int diff = origin_vector[0] + origin_vector[n-1];

    for (int current_minus_index=0; current_minus_index<n-1; current_minus_index++){
        for (int current_plus_index=n-1; current_plus_index>=0; current_plus_index--) {
            int current_dff = origin_vector[current_minus_index] + origin_vector[current_plus_index];

            if (current_plus_index <= current_minus_index) break;

            if (diff < 0 && current_dff < diff) break;


            if (optid_diff > abs(current_dff)){

                optid_diff = abs(current_dff);
                opt_plus = current_plus_index;
                opt_minus = current_minus_index;
            }

            diff = current_dff;

        }
    }

    cout << origin_vector[opt_minus] << " " << origin_vector[opt_plus];

    return 0;
}