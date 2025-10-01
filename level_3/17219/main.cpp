#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map <string, string> password_book;

    for (int i=0;i<N;i++) {
        string address, password;

        cin >> address >> password;

        password_book.insert({address, password});
    }

    for (int i=0;i<M;i++) {
        string address;

        cin >> address;

        cout << password_book[address] << '\n';
    }



    return 0;
}