//
//  main.cpp
//  leetCode22
//
//  Created by 张傲天 on 2017/2/13.
//  Copyright © 2017年 张傲天. All rights reserved.
//
// No.241
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//class Solution {
//public:
//    vector<int> answer;
//    vector<int> diffWaysToCompute(string input) {
//        get(input);
//        return answer;
//    }
//    void get(string input) {
//        int xinhaoliang = 0;
//        for (int i = 0; i < input.size(); i++) {
//            int isKuoHaol = 0;
//            int isKuoHaor = 0;
//            if ((input[i] == '+' ||input[i] == '-' ||input[i] == '*' )) {
//                xinhaoliang = 1;
//                //left
//                int l = i - 1;int left = 0;
//                if (input[l] == '(') {
//                    xinhaoliang = 0;
//                    continue;
//                }
//                if (input[l] == ')') {
//                    isKuoHaol = 1;
//                    while (input[l] != '(') {
//                        l--;
//                    }
//                    left = stoi(input.substr(l + 1,i - l - 1));
//                } else {
//                    while (input[l] <= '9' && input[l] >= '0') {
//                        //                    left = left + (input[l] - '0')*pow(10 ,i - l - 1);
//                        l--;
//                    }
//                    left = stoi(input.substr(l + 1,i - l - 1));
//                }
//                
//                //right
//                int r = i + 1;int right = 0;
//                if (input[r] == '(') {
//                    isKuoHaor = 1;
//                    while (input[r] != ')') {
//                        r++;
//                    }
//                    right = stoi(input.substr(i + 2,r - i - 2));
//                } else {
//                    while (input[r] <= '9' && input[r] >= '0') {
//                        right = right*pow(10 ,r - i - 1) + (input[r] - '0');
//                        r++;
//                    }
//                }
//                
//                int num = 0;
//                if (input[i] == '+') {
//                    num = left + right;
//                } if (input[i] == '-') {
//                    num = left - right;
//                } if (input[i] == '*') {
//                    num = left * right;
//                }
//                string sub = input;
//                if (isKuoHaol) {
//                    l--;
//                }
//                if (isKuoHaor) {
//                    r++;
//                }
//                if (num >= 0) {
//                    sub.replace(l + 1, r - l - 1, to_string(num));
//                } else
//                    sub.replace(l + 1, r - l - 1, '(' + to_string(num) + ')');
//                get(sub);
//            }
//        }
//        if (xinhaoliang == 0) {
//            if (input[0] == '(') {
////                if (find(answer.begin(), answer.end(), stoi(input.substr(1,input.size() - 2))) == answer.end()) {
//                    answer.push_back(stoi(input.substr(1,input.size() - 2)));
////                }
//            } else{
////                if (find(answer.begin(), answer.end(), stoi(input)) == answer.end()) {
//                    answer.push_back(stoi(input));
////                }
//            }
////                answer.push_back(stoi(input));
//        }
//    }
//};
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int size = (int)input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution* s = new Solution;
    string a = "2*3-4*5";
    vector<int> b = s->diffWaysToCompute(a);
    return 0;
}
