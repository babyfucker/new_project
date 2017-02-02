//
//  main.cpp
//  leetCode12(翻转链表)
//
//  Created by 张傲天 on 2017/2/2.
//  Copyright © 2017年 张傲天. All rights reserved.
//

#include <iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* answer;
        if (head->next == NULL || head == NULL) {
            return head;
        }
        ListNode* pre = head;//前
        ListNode* cur = head->next;//现在
        ListNode* next = nullptr;//下一个
        head->next = NULL;
        while (cur->next != NULL) {
            next = cur->next;//先把下一个保存下来
            cur->next = pre;//再把 现在的next 指向上一个
            pre = cur;//更新现在
            cur = next;//更新next
        }
        cur->next = pre;//最后一个节点
        return cur;
    }
};
int main() {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution* s = new Solution;
    ListNode* test = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    test->next = n2;
    n2->next = n3;
    ListNode* ans = s->reverseList(test);
    return 0;
    
}
