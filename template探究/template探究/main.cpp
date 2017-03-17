//
//  main.cpp
//  template探究
//
//  Created by 张傲天 on 2017/3/16.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
union u {
    int a = 0;
};
template <typename T>
T func(T& s) {
    return s;
}// 引用传递

template <typename T>
T func(T s) {
    return s;
}// 值传递

template <class T>
class theC {
private:
    T a;

public:
    theC(T k):a(k) {
        cout<<"here you are:"<<a<<endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<func("asd")<<endl;
    cout<<func(123)<<endl;
    cout<<func('a')<<endl;
    stack<int> s;
    u* theu = new u;
    cout<<func(&theu)<<endl;
    theC<class T> c;
    return 0;
}
