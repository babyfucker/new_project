//
//  main.cpp
//  c++派生类去初始化基类
//
//  Created by 张傲天 on 2017/3/16.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
using namespace std;

//class Base//显式调用基类的构造函数
//{
//private:
//    int n;
//    
//public:
//    Base(){ cout<<"default constructor is called\n"; n = 8;}
//    Base(int m):n(m){ cout<<"constructor is called\n";}
//    ~Base(){}
//};
//
//class Derive:public Base
//{
//private:
//    int n;
//    
//public:
//    Derive(int m):Base(m),n(m)
//    {
//    }
//    ~Derive(){}
//};

//-----------------------------------------

//class Base //不显示调用，没有符合情况的默认构造函数,编译错误
//{
//private:
//    int n;
//    
//public:
//    Base(int m):n(m){ cout<<"constructor is called\n";}
//    ~Base(){}
//};
//
//class Derive:public Base
//{
//private:
//    int n;
//    
//public:
//    Derive(int m):n(m)
//    {
//    }
//    ~Derive(){}
//};

//-----------------------------------------

class Base  //有符合情况的默认构造函数，不显示调用也没有关系
{
private:
    int n;
    
public:
    Base(){ cout<<"default constructor is called\n"; n = 8;}
    Base(int m):n(m){ cout<<"constructor is called\n";}
    ~Base(){ cout<<"default disconstructor is called\n"; }
};

class Derive:public Base
{
private:
    int n;
    
public:
    Derive(int m):n(m)
    {
    }
    ~Derive(){}
};

int main()
{
    Derive* a = new Derive(10);
    delete a;//不主动释放不会调用析构函数
    return 0;
}
