//
//  main.cpp
//  leetCode18
//
//  Created by 张傲天 on 2017/2/8.
//  Copyright © 2017年 张傲天. All rights reserved.
//
// No. 456 回溯法 与 递归
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> permute(vector<int> &nums, int begin, vector<vector<int>> &answers) {
            if (begin >= nums.size()) {
                answers.push_back(nums);
                return answers;
            }
            for (int i = begin; i < nums.size(); i++) {
                swap(nums[begin], nums[i]);
                permute(nums, begin + 1, answers);
                swap(nums[begin], nums[i]);
            }
            return answers;
        }
    };
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int> a = {1,2};
    a.insert(a.begin(), 0);
    vector<vector<int>> answers;
    Solution* s = new Solution;
    vector<vector<int>> b = s->permute(a,0,answers);
    return 0;
}
