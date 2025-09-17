
#include <iostream>

using namespace std;

int main () {
    int a = 123;
    // a의 주소를 가져오기 : &
    cout << a << " " << &a << endl;

    // int 주소 값을 저장할 수 있는 변수를 생성.
    int *b = &a; // 이러면 딱 int만큼만 값을 가쟈와서 다시 int로 출력을 할 것이다.
    cout << b << endl; //주소 값이 보인다. 
    //주소를 참조하여 저장된 값을 가져온다. 
    cout << *b << endl; //주소에서 참조된 값이 보인다. 

    *b = 567; 
    cout << a << " " << b << " " << *b << endl;
    // -> a도 값이 변해버린다. 
    // 왜냐하면 *b = 679를 하는 순간 value가 변한 것이기 때문이다.
    // name, address, value가 있으먄 name-address로 pair가 생기고, value가 변화하기 때문이다.



    // 포인터 자체의 주소 크기는 일정하다.
    // 집이 크다고 해서 주소가 다르지는 않다.
    double *c = nullptr;

    cout << sizeof(int) << " " <<  sizeof(double) << endl;
    cout << sizeof(int *) << " " <<  sizeof(double *) << endl;
    cout << sizeof(b) << " " <<  sizeof(c) << endl;


    // 포인터 연산과 배열
    // size_t는 해당 변수의 주소값을 가져온다.
    cout << sizeof(size_t) << endl;


    // 주소값의 차이는 의미가 있다.
    // 4만큼 차이가 난다. int가 4byte이기 때문이다.
    cout << size_t(b) << " " << size_t(b+1) << " " << size_t(b+2) << " " << endl;
    
    // 8만큼 차이가 난다. double이 8byte이기 때문이다.
    cout << size_t(c) << " " << size_t(c+1) << " " << size_t(c+2) << " " << endl;
    
    
    
    
    //포인터는 배열처럼 사용하는 경우가 많다.
    int my_array[] = {1,2,3,4,5,6};
    char my_str[] = {'a', 'b', 'c', 'd', 'e'};

    char *ptr = my_str;  //배열의 이름은 포인터이다. &가 필요없다.

    // 두 명령어는 같은 역할을 한다.
    cout << *(ptr + 3) << endl;
    cout << ptr[3] << endl;


    return 0;
}