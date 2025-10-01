#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    int method_count = 0;

    for (int two_count = 0; N - 2 * two_count >=0; two_count++){
        int one_count = N - 2 * two_count;

        int total_count = two_count + one_count;
        int second_count = total_count - one_count;

        int current_method = 1;

        for (int idx=0; idx < second_count; idx++){
            current_method *= total_count - idx;
            current_method %= 10007;
        }

        for (int idx=0; idx < second_count; idx++){
            current_method /= second_count - idx;
        }

        method_count += current_method;

    }


    cout << method_count % 10007 << '\n';
    

    return 0;
}
