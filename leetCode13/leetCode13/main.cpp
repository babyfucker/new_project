//
//  main.cpp
//  leetCode13
//
//  Created by 张傲天 on 2017/2/2.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        if (s.length() < 2) {
            return s;
        }
        int i = (int)s.length() - 1;//left
        int j = 0;//right
        for (i = (int)s.length() - 1; i > 0; i--) {
            if (s[i] == '[') {
                j = i + 1;
                while (s[j] != ']') {
                    j++;
                }
                string inside = decodeString(s.substr(i + 1,j - i - 1));
                string answer;
                int times = 0;
                int h = i - 1;
                int weishu = 0;
                while (s[h] <= '9' && h >= 0) {
                    h--;
                    weishu++;
                }
                times = atoi(s.substr(h + 1,weishu).data());
                for (int k = 0; k < times; k++) {
                    answer = answer + inside;
                }
                s.replace(i - weishu, j - i + weishu + 1,answer);
            }
        }
        return s;
    }
};
int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
//    int a = '9';
//    char b = 96;
//    cout<<a<<endl;
    Solution *s = new Solution;
    cout<<s->decodeString("11[a]");
//    string a = "0123456789";
//    a.replace(3, 4, "asd");
//    cout<<a<<endl;
    return 0;
}
