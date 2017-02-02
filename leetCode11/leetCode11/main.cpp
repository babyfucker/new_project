//
//  main.cpp
//  leetCode11
//
//  Created by 张傲天 on 2017/2/2.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        int i = (int)nums.size() - 1;
        while(i > 0) {
            if (nums[i - 1] > nums[i])
                return nums[i];
            i--;
        }
        return min;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution * s = new Solution;
    vector<int> test = {1,1};
    cout<<s->findMin(test)<<endl;
    return 0;
}
