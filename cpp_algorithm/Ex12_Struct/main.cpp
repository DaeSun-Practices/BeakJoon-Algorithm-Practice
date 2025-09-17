#include <iostream>
#include <cstring>

using namespace std;

struct MyStruct 
{
    int first;
    int second;

    int Sum()
    {
        return first + second;
    }
}; // 하나의 변수 타입이 되는 것이다.


int main () {
    MyStruct a;
    a.first = 42;
    a.second = 54;

    // 오! 변수들의 합 만큼 메모리를 사용한다
    // 가끔 그것보다 더 큰 사이즈가 나오는 경우도 있다.
    cout << sizeof(a) << endl;
    
    cout << a.Sum() << endl;


    // Struct에 포인터도 붙혀줄 수 있다.
    MyStruct * ptr_a = &a;

    // 포인터는 member(->) operator가 화살표
    // 함수도 ->로 호출할 수 있다는 것은 처음 알았다.
    cout << ptr_a -> first << " " << ptr_a -> second << " " << ptr_a -> Sum() << endl;


    // 배열도 가능
    MyStruct pairs[10];

    for (int i=0; i<10;i++) {
        pairs[i].first = i;
        pairs[i].second = i*10;
    }

    for (int i=0; i<10;i++) {
        cout << pairs[i].Sum() << endl;
    }


    return 0;
}