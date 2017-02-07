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
#include <vector>
using namespace std;
class Solution {
public:
//    string decodeString(string s) {
//        int i = 0;//left
//        int j = 0;//right
//        vector<int> l;
//        vector<int> r;
//        vector<int> lborder;
//        vector<int> rborder;
//        for (int z = 0; z < s.length(); z++) {
//            if (s[z] == '[') {
//                l.push_back(z);
//            }
//            if (s[z] == ']') {
//                r.push_back(z);
//            }
//        }
//        if (l.size() == 0) {
//            return s;
//        }
//        if (l.size() == 1) {
//            lborder.push_back(l[0]);
//            rborder.push_back(r[0]);
//        } else {
//            lborder.push_back(l[0]);
//            int xinhaoliang = 0;
//            for (int n = 0; n < l.size() - 1; n++) {
//                if (l[n + 1] > r[n]) {
//                    if (xinhaoliang == 0) {
//                        rborder.push_back(r[n]);
//                        xinhaoliang = 1;
//                    }
//                    lborder.push_back(l[n + 1]);
//                    rborder.push_back(r[n + 1]);
//                }
//            }
//            if (xinhaoliang == 0) {
//                rborder.push_back(r[r.size() - 1]);
//                xinhaoliang = 1;
//            }
//        }
//        int cha = 0;
//        for (int m = 0; m < (int)lborder.size(); m++) {
//            i = lborder[m] - cha;
//            j = rborder[m] - cha;
//            string inside = decodeString(s.substr(i + 1,j - i - 1));
//            string answer;
//            int times = 0;
//            int h = i - 1;
//            int weishu = 0;
//            while (s[h] <= '9' && h >= 0) {
//                h--;
//                weishu++;
//            }
//            times = atoi(s.substr(h + 1,weishu).data());
//            for (int k = 0; k < times; k++) {
//                answer = answer + inside;
//            }
//            s.replace(i - weishu, j - i + weishu + 1,answer);
//            cha = cha + j - i + weishu + 1- (int)answer.size();
//        }
//        return s;
//    }
    string decodeString(string s, int *i) {
        string res;
        
        while (*i < s.length() && s[*i] != ']') {
            if (!isdigit(s[*i]))
                res += s[(*i)++];
            else {
                int n = 0;
                while (*i < s.length() && isdigit(s[*i]))
                    n = n * 10 + s[(*i)++] - '0';
                
                (*i)++; // '['
                string t = decodeString(s, i);
                (*i)++; // ']'
                
                while (n-- > 0)
                    res += t;
            }
        }
        
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, &i);
    }
};
int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution *s = new Solution;
    cout<<s->decodeString("10[b]4[ch]")<<endl;
    return 0;
}
