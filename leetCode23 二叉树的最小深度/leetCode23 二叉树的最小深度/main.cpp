//
//  main.cpp
//  leetCode23 二叉树的最小深度
//
//  Created by 张傲天 on 2017/2/13.
//  Copyright © 2017年 张傲天. All rights reserved.
//
//No.111
#include <iostream>
using namespace std;
/**/
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void minDepth(TreeNode* root, int & min, int depth) {
        if (root == NULL) {
            if (depth < min) {
                min = depth;
            }
            return ;
        } else {
            depth++;
            if(depth < min) {
                minDepth(root->left, min, depth);
                minDepth(root->right, min, depth);
            }
        }
    }
    int minDepth(TreeNode* root) {
        int min = 0x7fffffff;
        minDepth(root, min, 0);
        return min;
    }
};
int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a = 0x7fffffff;//最大值
    int b = 0X00000000;//0
    int c = 0xffffffff;//-1;
    int d = 0x00000001;//1;
    int e = 0x80000000;//最小值
    int f = 0x80000001;//次小值
    cout<<a<<endl;
    return 0;
}
