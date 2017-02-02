//
//  main.cpp
//  leetCode3
//
//  Created by 张傲天 on 2016/12/29.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[k] = nums [i];
                if(i != k)
                    nums[i] = 0;
                k++;
            }
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    vector<int> nums = {1, 1, 0, 3, 12};
    Solution * s = new Solution;
    s->moveZeroes(nums);
    
    return 0;
}
