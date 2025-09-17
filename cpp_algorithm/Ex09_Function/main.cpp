
#include <iostream>

using namespace std;

// 함수는 선언과 정의가 분리가능하다.
int Add (int a, int b){
    return a+b;
}

void Add (int a, int b, int * c){
    *c = a + b;
}



int main () {
    cout << Add(1, 2) << endl;

    int sum;
    Add(2, 3, &sum);

    cout << sum << endl;

    return 0;
}