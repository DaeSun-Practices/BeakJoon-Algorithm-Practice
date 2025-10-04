#include <bits/stdc++.h>

using namespace std;

int desc_sort(int a, int b){
    return a > b;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> min_heap;

    for (int _=0; _<N; _++){
        int x;
        cin >> x;
        if (x==0){
            if (min_heap.size() == 0){
                cout << 0 << '\n';
            }
            else{
                sort(min_heap.begin(), min_heap.end(), desc_sort);
                int small = min_heap.back();
                cout << small << '\n';
                min_heap.pop_back();
            }
        }
        else {
            min_heap.push_back(x);
        }
    }
}