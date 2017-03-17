//
//  main.cpp
//  leetCode24
//
//  Created by 张傲天 on 2017/2/26.
//  Copyright © 2017年 张傲天. All rights reserved.
//

//No.61
#include <iostream>
/**
Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link
        
        if(k %= len)
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;
    }
};
//class Solution {
//public:
//    ListNode* rotateRight(ListNode* head, int k) {
//        ListNode* answer = head;
//        ListNode* preHead = head;
//        int i = 0;
//        while (head->next != NULL) {
//            if (i == k) {
//                answer = head->next;
//                head->next = NULL;
//                head = answer;
//                i++;
//            } else {
//                i++;
//                head = head->next;
//            }
//        }
//        if (i != 0) {
//           head->next = preHead;
//        }
//        return answer;
//    }
//};
int main() {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
//    node2->next = node3;
//    node3->next = node4;
//    node4->next = node5;
    Solution* s = new Solution;
    ListNode * node = s->rotateRight(node1, 1);
    
    return 0;
}
