//
//  main.cpp
//  leetCode10
//
//  Created by 张傲天 on 2017/2/1.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        map<char,int> map;
        for (int i = 0,j = 0; i < s.length(); ++i) {
            if (s[i] == '\0') {
                break;
            }
            if (map.find(s[i]) != map.end()) {
                j = map[i] + 1;
            } else
                map[s[i]] = i;
            answer = max(answer,i-j+1);
        }
        return answer;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution * s = new Solution;
    string test ="pwwkew";
    cout<<s->lengthOfLongestSubstring(test);
    return 0;
}
