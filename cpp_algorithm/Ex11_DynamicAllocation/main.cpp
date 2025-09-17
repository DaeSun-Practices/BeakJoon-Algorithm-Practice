#include <iostream>
#include <cstring>

using namespace std;

const int kMaxStr = 100;

int Min(int a, int b)
{
    return a < b ? a : b; // 조건연산자(삼항연산자)
}


int main () {
    char str1[] = "Hello, World!";
    char str2[kMaxStr];

    // str2 = str1 이런 방식으로는 복사가 안됨. 

    // dest, src, 메모리 크기 (복사할 메모리 크기를 생각해야 함.)
    // memcpy cstring 라이브러리 활용
    memcpy(str2, str1, Min(sizeof(str1), sizeof(str2)));
    cout << str2 << endl;

    //정적 배열 : stack
    //동적 배열 : heap사용.

    // 이것은 동적 배열이다. //동적 배열은 배열이 아니다! 
    // 사실은 주소와 그에 해당하는 메모리 공간을 할당 받았을 뿐이다!
    char * dynamic_array = new char[kMaxStr];

    // 동적할당으로 받은 메모리도 비슷하게 사용할 수 있다.
    memcpy(dynamic_array, str1, Min(sizeof(str1), kMaxStr));
    cout << dynamic_array << endl;
    

    // str1, str2는 좀 앞의 메모리를 사용하고, dynamic_array는 좀 뒤의 메모리를 사용한다.
    // 사용하는 메모리의 영역이 다른 것이다!
    cout << size_t(str1) << " " << size_t(str2) << " "  << size_t(dynamic_array) << " ";

    delete[] dynamic_array;

    return 0;
}