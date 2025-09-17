#ifndef MY_CLASS_H
#define MY_CLASS_H

class MyClass
{
public:
    MyClass();
    MyClass(int number);
    ~MyClass();

    void Increment(int a);
    void Print();

private:
    int number_ = 0;
};

#endif //MY_CLASS_H