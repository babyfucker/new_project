//
//  main.cpp
//  leetCode1
//
//  Created by 张傲天 on 2016/12/14.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
//vector<int> view;
int get_deepth(TreeNode *node) {
    if (node == NULL)
        return 0;
    int left_deepth = get_deepth(node->left);
    int right_deepth = get_deepth(node->right);
    if (get_deepth(node->left) >= get_deepth(node->right)) {
        return left_deepth + 1;
    }
    return right_deepth + 1;
}
void get_value(TreeNode* root,int level,vector<int> view) {
    if (root == NULL)
        return ;
    if (level > view.size()) {
        view.push_back(root->val);
    }
    get_value(root->right, level + 1, view);
    get_value(root->left, level + 1, view);
    
}

class Solution {
public:
    vector<int> view;
    void get_value(TreeNode* root,int level) {
        if (root == NULL)
            return ;
        if (level > view.size()) {
            view.push_back(root->val);
        }
        get_value(root->right, level + 1);
        get_value(root->left, level + 1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        get_value(root,1);
        for (int i = 0; i < view.size(); i++) {
            cout<<view[i]<<endl;
        }
        return view;
    }
};
int main(int argc, const char * argv[]) {
    
    TreeNode node_1 = *new TreeNode(1);
    TreeNode node_2 = *new TreeNode(2);
    TreeNode node_3 = *new TreeNode(3);
    TreeNode node_4 = *new TreeNode(4);
    TreeNode node_5 = *new TreeNode(5);
    TreeNode node_6 = *new TreeNode(6);
    TreeNode node_7 = *new TreeNode(7);
    //构造一棵二叉树
    node_1.left = &node_2;
    node_1.right = &node_3;
//    node_2.left = &node_4;
//    node_3.right = &node_6;
//    node_4.right = &node_5;
//    node_5.left = &node_7;

    Solution solution = *new Solution;
    solution.rightSideView(&node_1);

    return 0;
}
