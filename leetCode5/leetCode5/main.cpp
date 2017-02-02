//
//  main.cpp
//  leetCode5
//
//  Created by 张傲天 on 2016/12/29.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseString(string s) {
        string r;
        for (int i = (int)s.size() - 1;i >= 0;i--)
            r += s[i];
        return r;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution *s = new Solution;
    cout<<s->reverseString("hello");
    return 0;
}
