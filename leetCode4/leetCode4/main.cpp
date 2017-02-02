//
//  main.cpp
//  leetCode4
//
//  Created by 张傲天 on 2016/12/29.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//class NumMatrix {
//public:
//    vector<vector<int>> Matrix;
//    NumMatrix(vector<vector<int>> &matrix) {
//        Matrix = matrix;
//    }
//    
//    int sumRegion(int row1, int col1, int row2, int col2) {
//        int sum = 0;
//        for (int i = row1; i <= row2 ; i++) {
//            for (int j = col1; j <= col2; j++) {
//                sum += Matrix[i][j];
//            }
//        }
//        return sum;
//        
//    }
//};
class NumMatrix {
private:
    int row, col;
    vector<vector<int>> sums;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        row = (int)matrix.size();
        col = row>0 ? (int)matrix[0].size() : 0;
        sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sums[i][j] = matrix[i-1][j-1] +
                sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    vector<vector<int>> m;
    m = {{3, 0, 1, 4, 2},
                                  {5, 6, 3, 2, 1},
                                  {1, 2, 0, 1, 5},
                                  {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};
    NumMatrix * n = new NumMatrix(m);
    cout<<n->sumRegion(2, 1, 4, 3);
    cout<<n->sumRegion(1, 1, 2, 2);
    return 0;
}
