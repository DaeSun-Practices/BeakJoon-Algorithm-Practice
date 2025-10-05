#include <bits/stdc++.h>

using namespace std;


int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C;
    cin >> A >> B >> C;

    long long start = ((A % C) * (A % C)) % C;
    B -= 2;

    vector<long long> remains;
    remains.push_back(A % C);
    remains.push_back(start);

    bool is_found = false;
    for (int _=0; _<B; _++){
        start = (start * A) % C;

        if (find(remains.begin(), remains.end(), start) == remains.end()){
            remains.push_back(start);
        }
        else {
            break;
        }
    }

   
    if (!is_found){
        cout << start;
    }
    else {
        B += 2;
        long long target_remain = (B % remains.size() - 1);
        if (target_remain == -1) {
            target_remain = remains.size() - 1;
        }

        cout << remains[target_remain-1];
    }
       
 

    return 0;
}