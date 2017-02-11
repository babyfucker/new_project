//
//  main.cpp
//  leetCode15
//
//  Created by 张傲天 on 2017/2/7.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(int argc, const char * argv[]) {
    Solution* s = new Solution;
    vector<int> a = {2, 5};
    s->coinChange(a, 3);
    return 0;
}
