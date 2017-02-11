//
//  main.cpp
//  leetCode20
//
//  Created by 张傲天 on 2017/2/11.
//  Copyright © 2017年 张傲天. All rights reserved.
//
//No. 260
#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> answer;
        map<int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = i;
                answer.push_back(nums[i]);
            } else {
                answer.erase(find(answer.begin(), answer.end(), nums[i]));
            }
        }
        return answer;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution* s = new Solution;
    vector<int> a = {1, 2, 1, 3, 2, 5};
    vector<int> ans = s->singleNumber(a);
    return 0;
}
