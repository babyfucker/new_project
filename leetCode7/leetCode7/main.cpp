//
//  main.cpp
//  leetCode7
//
//  Created by 张傲天 on 2016/12/29.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0;
        int j = 0;
        int l1 = (int)s.size();
        int l2 = (int)p.size();
        int n = l1 > l2 ? l1 : l2;
        cout<<n<<endl;
//        while (i < (int)s.size() && j < (int)p.size()) {
//            if (s[i] == s[j]) {
//                i++;
//                j++;
//            } if (s[i] == '?' || s[j] == '?') {
//                if (s[j] == '*') {
//                    i++;
//                } if (s[i] == '*') {
//                    j++;
//                } else {
//                    i++;
//                    j++;
//                }
//            }
//        }
        for (int k = 0; k < n; k++) {
            if (s[i] != s[j]) {
                return false;
            } else {
                if (i < (int)s.size() - 1)
                    i++;
                if (j < (int)s.size() - 1)
                    j++;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution* s = new Solution;
    bool a1 = s->isMatch("aa","a");
    bool a2 = s->isMatch("aa","aa");
    bool a3 = s->isMatch("aaa","aa");
    bool a4 = s->isMatch("aa", "*");
    bool a5 = s->isMatch("aa", "a*");
    bool a6 = s->isMatch("ab", "?*");
    bool a7 = s->isMatch("aab", "c*a*b");
    return 0;
}
