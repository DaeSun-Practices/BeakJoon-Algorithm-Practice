#include <iostream>
#include <cstring>

#include "MyClass.h"

using namespace std;


MyClass::MyClass()
{
    // 호출 시점 확인
    cout << "MyClass()" << endl;
}

MyClass::MyClass(int number)
{
    cout << "MyClass(int number)" << endl;

    // this pointer 소개
    this->number_ = number;
}

MyClass::~MyClass()
{
    // 호출 시점 확인
    cout << "~MyClass()" << endl;
}

void MyClass::Increment(int a)
{
    number_ += a;
}

void MyClass::Print()
{
    cout << number_ << endl;
}

