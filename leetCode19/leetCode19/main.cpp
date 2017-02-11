//
//  main.cpp
//  leetCode19
//
//  Created by 张傲天 on 2017/2/11.
//  Copyright © 2017年 张傲天. All rights reserved.
//
// No. 494
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void backTrack(vector<int>& nums, int begin, int S, int& answers) {
        if (begin == nums.size() - 1) {
            if (nums[begin] == S) {
                answers++;
            } if (nums[begin] == -S) {
                answers++;
            }
            return;
        }
        backTrack(nums, begin + 1, S - nums[begin], answers);
        backTrack(nums, begin + 1, S + nums[begin], answers);
        
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int answer = 0;
        backTrack(nums, 0, S, answer);
        return answer;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution* s = new Solution;
    vector<int> a = {1, 0};
    cout<<s->findTargetSumWays(a, 1)<<endl;
    return 0;
}
