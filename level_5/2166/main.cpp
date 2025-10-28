#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;


    long long x1, y1, x_first, y_first, xn, yn;
    long long total1=0;
    long long total2=0;
    cin >> x1 >> y1;
    
    x_first = x1;
    y_first = y1;

    for (int _=1; _<N; _++){
        cin >> xn >> yn;

        total1 +=x1*yn;
        total2 += y1*xn;

        //cout << _ << " "<< x1 << " " << yn << '\n';
        //cout << _ << " "<< y1 << " " << xn << '\n';
        
        x1 = xn;
        y1 = yn;
    }

    total1 += xn*y_first;
    total2 += yn*x_first;

    //cout << N << " "<< xn << " " << y_first << '\n';
    //cout << N << " " << yn << " " << x_first << '\n';
    

    double total =  (total1 - total2) / 2.0;
    if (total < 0.0) total *= -1.0;

    cout << total;
    
    
    return 0;
}
