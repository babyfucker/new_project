//
//  main.cpp
//  leetCode14
//
//  Created by 张傲天 on 2017/2/7.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() < 1) {
            return s;
        }
        string answer;
        string originals = s;
        reverse(s.begin(), s.end());
        int i = (int)originals.size();
        int j = 0;
        while (i > 0) {
            if (originals.substr(0,i) == s.substr(j,s.size() - j)) {
                answer = s.substr(0,j) + originals;
                break;
            }
            i--;
            j++;
        }
        return answer;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution* s = new Solution;
    cout<<s->shortestPalindrome("aacecaaa")<<endl;
    return 0;
}
