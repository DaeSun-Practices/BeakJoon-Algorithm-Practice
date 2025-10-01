#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string parse = "IOI";

    int awnser = 0;

    int M;
    cin >> M;

    string total_string;
    cin >> total_string;

    
    bool is_matched = false;
    int serial_matched = 0;

    for (int i=0; i < M-2; ++i) {
        string sub_total_string = total_string.substr(i,3);
        
        if (sub_total_string == parse){
            is_matched = true;
            i++;
            serial_matched++;
        }
        else{
            if(is_matched){
                is_matched = false;
                
                if (serial_matched >= N){
                    awnser += serial_matched - N +1;
                }

                serial_matched = 0;

            }
        }
    }

    if (serial_matched >= N){
        awnser += serial_matched - N +1;
    }


    cout << awnser << '\n';
    
    return 0;
}