//
//  main.cpp
//  leetCode16
//
//  Created by 张傲天 on 2017/2/7.
//  Copyright © 2017年 张傲天. All rights reserved.
//


//No. 328
#include <iostream>
using namespace std;
/**
Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead;
        ListNode* oddTail;
        ListNode* evenHead;
        ListNode* evenTail;
        ListNode* node;
        ListNode* headLength = head;
        int n = 0;
        while (headLength != NULL) {
            headLength = headLength->next;
            n++;
        }
        if (n <= 2) {
            return head;
        } else if (n == 3) {
            oddHead = head;
            evenHead = head->next;
            oddTail = evenHead->next;
            oddHead->next = oddTail;
            oddTail->next = evenHead;
            evenHead->next = NULL;
            return oddHead;
        } else {
            oddHead = head;
            evenHead = head->next;
            oddTail = evenHead->next;
            evenTail = oddTail->next;
            oddHead->next = oddTail;
            evenHead->next = evenTail;
            node = evenTail->next;
            int i = 5;
            while (node != NULL) {
                if (i%2 == 1) {
                    oddTail->next = node;
                    oddTail = oddTail->next;
                } if (i%2 == 0) {
                    evenTail->next = node;
                    evenTail = evenTail->next;
                }
                node = node->next;
                i++;
            }
            oddTail->next = evenHead;
            evenTail->next = NULL;
        }
        return oddHead;
    }
};

int main() {
    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution* s = new Solution;
    ListNode* test1 = new ListNode(1);
    ListNode* test2 = new ListNode(2);
    ListNode* test3 = new ListNode(3);
    ListNode* test4 = new ListNode(4);
    ListNode* test5 = new ListNode(5);
    ListNode* test6 = new ListNode(6);
    test1->next = test2;
    test2->next = test3;
    test3->next = test4;
    test4->next = test5;
    test5->next = test6;
    ListNode* a = s->oddEvenList(test1);
    return 0;
}
