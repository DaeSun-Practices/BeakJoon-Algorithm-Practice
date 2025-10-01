#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;


    int total = 0;

    for (int two_count = 0; N - 2 * two_count >= 0; two_count++){
        int one_count = N - 2 * two_count;

        for (int two_one_count = 0; two_count - two_one_count >= 0; two_one_count++){
            int two_two_count = two_count - two_one_count;

            int currnt_count = 1;
            
            int total_count = one_count + two_count;

            for (int i=0; i < total_count - one_count; i++){
                currnt_count *= total_count - i;
                currnt_count %= 10007;
            }

            for (int i=0; i < two_one_count; i++){
                currnt_count /= two_one_count - i;
            }

            for (int i=0; i < two_two_count; i++){
                currnt_count /= two_two_count - i;
            }

            total += currnt_count;
        }
    }

    cout << total % 10007 << '\n';


    return 0;
}