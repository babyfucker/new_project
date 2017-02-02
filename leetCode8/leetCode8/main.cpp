//
//  main.cpp
//  leetCode8
//
//  Created by 张傲天 on 2017/1/31.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
#include <vector>
#include <__hash_table>
#include <unordered_map>
#include <map>
using namespace std;
class Solution {
public:
//vector<string> findRepeatedDnaSequences(string s) {
//            unordered_map<int, int> m;
//            vector<string> r;
//            int t = 0, i = 0, ss = (int)s.size();
//            while (i < 9)
//                t = t << 3 | (s[i++] & 7);
//            while (i < ss)
//                if (m[t = (t << 3 & 0x3FFFFFFF) | (s[i++] & 7)]++ == 1)
//                    r.push_back(s.substr(i - 10, 10));
//            return r;
//        }

//vector<string> findRepeatedDnaSequences(string s) {
//        char  hashMap[1048576] = {0};
//        vector<string> ans;
//        int len = (int)s.size(),hashNum = 0;
//        if (len < 11) return ans;
//        for (int i = 0;i < 9;++i)
//            hashNum = (hashNum << 2) | (s[i] - 'A' + 1) % 5;
//        for (int i = 9;i < len;++i)
//            if (hashMap[hashNum = (hashNum << 2 | (s[i] - 'A' + 1) % 5) & 0xfffff]++ == 1)
//                ans.push_back(s.substr(i-9,10));
//        return ans;
//    }
    
vector<string> findRepeatedDnaSequences(string s) {
    vector<string> answer;
    map<string,string> dnamap;
    string temp;
    if(s.length() <= 10)
        return answer;
    for (int i = 0; i < s.length() - 9; i++) {
        temp = s.substr(i,10);
        if (i == 0) {
            dnamap[temp] = temp;
        } else {
            if (dnamap.find(temp) != dnamap.end()) {
                answer.push_back(temp);
            } else {
                dnamap[temp] = temp;
                }
            }
        }
    return answer;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution *s = new Solution;
    vector<string> ans = s->findRepeatedDnaSequences("AAAAAAAAAAA");
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}
