//
//  main.cpp
//  leetCode9
//
//  Created by 张傲天 on 2017/2/1.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int shit = 0x7fffffff;
        int height = (int)matrix.size();
        if (height == 0) {
            return answer;
        }
        int width = (int)matrix[0].size();
        int i = 0,j = 0;
        for(int k = 0;k < height*width;k++) {
            answer.push_back(matrix[i][j]);
            matrix[i][j] = shit;
            
            if (i > 0&&matrix[i-1][j] != shit) {
                i--;
                if ((i == height - 1||matrix[i+1][j] == shit)&&matrix[i][j-1] != shit&&j > 0) {
                    j--;
                    i++;
                }
            } else if (j < width - 1&&matrix[i][j+1] != shit) {
                j++;
            } else if (i < height - 1&&matrix[i+1][j] != shit) {
                i++;
            } else if (j > 0&&matrix[i][j-1] != shit) {
                j--;
            }
        }
        return answer;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution * s = new Solution;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};//{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    vector<int> ans = s->spiralOrder(matrix);
    std::cout << "Hello, World!\n";
    return 0;
}
