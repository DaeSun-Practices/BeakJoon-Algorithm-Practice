#include <iostream>

using namespace std;

int main () {
   int i = 20;
   
   cout << i << " " << sizeof(i) << endl; // 4byte


   float f = 123.456f;
   double d = 1234.5678;

   cout << f << " " << sizeof(f) << endl; // 4byte
   cout << d << " " << sizeof(d) << endl; // 8byte


   char a = 'a'; // 글자 하나의 리터럴
   cout << a << " " << sizeof(a) << endl; // 1byte

   char b[] = "b"; // 글자 여러개의 리터럴 // 엄밀히 따지면 이는 std::string 이다.
   cout << b << " " << sizeof(b) << endl; // 2byte

   char c[] = "char"; // 글자 여러개의 리터럴 // 이 경우, 배열 때문에 1byte가 추가되는 것 같다.
   cout << c << " " << sizeof(c) << endl; // 5byte



    i = 987.645; //강제 형변환
    cout << "i 강제 형변환: " << i << endl; //소숫점은 버림.

    f = 567.89; // f가 안붙어 있음으로 double이다. 이 double을 강제로 float로 형변환 하는 것이다.



    // i = 987;
    i += 100;
    i++;
    cout << "i " << i << endl; //소숫점은 버림.










}
