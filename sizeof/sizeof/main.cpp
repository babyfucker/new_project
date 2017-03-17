//
//  main.cpp
//  sizeof
//
//  Created by 张傲天 on 2016/10/14.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#include <iostream>
#include <iostream>
using namespace std;

void foo(char ca[],char c) {
    cout<<"ca: "<<sizeof(ca)<<endl; //警告已经说了,sizeof的函数参数会返回指针的内存大小，而不是函数大小
    cout<<"c: "<<sizeof(c)<<endl;
}

void foo_1(char (&ca)[],char c) {
    cout<<"ca 引用传递: "<<sizeof(ca[0])<<endl; //警告已经说了,sizeof的函数参数会返回指针的内存大小，而不是函数大小
    cout<<"c: "<<sizeof(c)<<endl;
}

struct test_s {
};

struct test_s1 {
    char a;
    int b;
};

struct S3 {
    char c1;
    test_s1 s;
    char c2[3];
};

class Student {
public:
    int a=100;
    char b='0';
    char d[6];
//    virtual void func_0();
private:
    int func();
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    cout<<sizeof(int)<<endl;
    cout<<sizeof(char)<<endl;
    cout<<sizeof(string)<<endl;
    cout<<sizeof(float)<<endl;
    cout<<sizeof(double)<<endl;
    cout<<"long:"<<sizeof(long)<<endl;
    cout<<sizeof(unsigned int)<<endl;
    
    int *ptr;
    int val=100;
    ptr=&val;
    cout<<"ptr:"<<sizeof(ptr)<<endl;
    cout<<sizeof(*ptr)<<endl;
    
    char *cptr;
    char cval='a';
    cptr=&cval;
    cout<<"cptr:"<<sizeof(cptr)<<endl;
    cout<<sizeof(*cptr)<<endl;
    cout<<sizeof(cval)<<endl;
    
    int array[100]={};
    cout<<sizeof(array)<<endl;//结果为4*100
    cout<<sizeof(*array)<<endl;
    cout<<"array:"<<*array<<endl;
    
    char carray[]="asdsdfgh";
    char carray_0[99];
    string s="asd";
    cout<<"carray: "<<sizeof(carray)<<endl;// 结果为4，字符末尾还存在一个NULL终止符
    cout<<"carray_0: "<<sizeof(carray_0)<<endl;//结果为3
    cout<<sizeof(s)<<endl;
    cout<<sizeof(s[1])<<endl;
    
    foo(carray_0,'a');
//    foo_1(carray,'a');
    
    cout<<sizeof(test_s)<<endl;//空的结构体为“1”
    cout<<sizeof(test_s1)<<endl;//字节对齐
    cout<<sizeof(S3)<<endl;//字节对齐
    
    Student stu1;
    cout<<"stu1: "<<sizeof(stu1)<<endl;//字节对齐
    
    int* i = new int(98);
    double* j = (double *)malloc(98);
    cout<<"动态内存分配new: "<<sizeof(*i)<<endl;
    cout<<"动态内存分配malloc: "<<sizeof(*j)<<endl;
    return 0;
}
