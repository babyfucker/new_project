//
//  main.cpp
//  c++)
//
//  Created by 张傲天 on 2017/3/4.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
using namespace std;
class X {
public:
    X() {
        cout<<"X 的构造函数"<<endl;
    }
    ~X() {
        cout<<"X 的析构函数"<<endl;
    }
};
class Y:X {
public:
    Y() {
        cout<<"Y 的构造函数"<<endl;
    }
    ~Y() {
        cout<<"Y 的析构函数"<<endl;
    }
};
//请问运行Test函数会有什么样的结果？
//答：程序崩溃。因为GetMemory并不能传递动态内存，Test函数中的str一直都是NULL。
void GetMemory(char **p)
{
    *p=(char*)malloc(100);
}

void Test(void)
{
    char *str = NULL;
    GetMemory(&str);
    strcpy(str,"helloworld");
    printf("%s", str);
}

//请问运行Test函数会有什么样的结果？
//答：可能是乱码。因为GetMemory返回的是指向“栈内存”的指针，该指针的地址不是NULL，但其原先的内容已经被清除，新内容不可知。
char *GetMemory_1(void)
{
    char p[]="helloworld";
    return p;
}
void Test_1(void)
{
    char *str = NULL;
    str = GetMemory_1();
    printf("%s", str);
}

//请问运行Test函数会有什么样的结果？
//答：（1）能够输出hello（2）内存泄漏
void GetMemory2(char **p, int num)
{
    *p = (char*)malloc(num);
}
void Test_2(void)
{
    char *str = NULL;
    GetMemory2(&str, 100);
    strcpy(str, "hello");
    printf("%s", str);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
//    Test();
//    Test_1();
//    Test_2();
    
    Y *y = new Y;
//    X *x = X;
    delete y;
    return 0;
}
