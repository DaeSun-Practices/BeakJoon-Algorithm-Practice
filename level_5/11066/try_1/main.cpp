#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, N;
    long long x;
    cin >> T;

    long long aweser[T];

    for (int _=0; _<T; _++){
        cin >> N;

        vector<long long> file_vector;

        long long cost = 0;
        long long temp = 0;


        for (int i=0; i<N; i++){
            cin >> x;
            file_vector.push_back(x);
        }

        sort(file_vector.begin(), file_vector.end(), greater());
        //for (long long y : file_vector) cout << y << " ";

        while (file_vector.size() > 1){
            temp = 0;

            temp += file_vector.back();
            file_vector.pop_back();
            temp += file_vector.back();
            file_vector.pop_back();

            file_vector.push_back(temp);
            cost += temp;

            sort(file_vector.begin(), file_vector.end(), greater());
        }

        aweser[_] = cost;
    }

    for (int i=0; i<T; i++) {
        cout << aweser[i] << endl;
    }

    return 0;
}