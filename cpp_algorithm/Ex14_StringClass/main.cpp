/*
    홍정모 연구소 https://honglab.co.kr/
*/

#include <iostream>
#include <cstring>

using namespace std;

class MyString 
{
public:
    MyString(char * input_str)
    {
        class_str = input_str;

        cout << "const char * input_str" << endl;
    }

    void Print() {
        cout << class_str << endl;
    }

    void Append(MyString * appended_class) {
        char * appended_str = appended_class->class_str;
        char new_str[strlen(class_str) + strlen(appended_str)];

        int previous_index = 0;
        while (true) {
            if (class_str[previous_index] == '\0'){
                break;
            }

            new_str[previous_index] = class_str[previous_index];

            previous_index ++;
        }

        for (int i = 0; i < sizeof(appended_str); i++){
            new_str[previous_index + i] = appended_str[i];

            if (appended_str[i] == '\0'){
                break;
            }

        }

        this -> class_str = new_str;

        cout << class_str << endl;
    }


private:
    char * class_str = "";
};

int main()
{
    // 클래스 기본 문법 안내

    MyString str1("ABCDE"); // 생성자 이용
    MyString str2("123");


    str1.Print();

    str1.Append(&str2); // 주소 넣어줌

    str1.Print();

    return 0;
}