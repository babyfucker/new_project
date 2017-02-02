//
//  main.cpp
//  leetCode0
//
//  Created by 张傲天 on 2016/12/14.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=(int)num1.length()-1;
        int n2=(int)num2.length()-1;
        int n = n1;
        if (n1 > n2) {
            for (int i = 0; i < n1 - n2; i++) {
                num2 = '0' + num2;
            }
            n = n1;
        } if (n1 < n2) {
            for (int i = 0; i < n2 - n1; i++) {
                num1 = '0' + num1;
            }
            n = n2;
        }
        int jinwei=0;
        int sum=0;
        string s="";
        
        while (n >= 0) {
            sum = (int)num1[n] + (int)num2[n] - '0' * 2 + jinwei;
            int a = sum%10;
            jinwei = sum / 10;
            s=(char)(a + '0')+s;
            if (n <= 0 && jinwei > 0) {
                s=(char)(jinwei + '0') + s;
            }
            n--;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution = *new Solution;
    cout<<solution.addStrings("9", "99");
       return 0;
}
