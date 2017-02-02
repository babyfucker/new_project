//
//  main.cpp
//  leetCode6
//
//  Created by 张傲天 on 2016/12/29.
//  Copyright © 2016年 张傲天. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
//        ListNode* HEAD = head;
//        while (head != NULL) {
//            if (head->val == val) {
//                if (HEAD == head)
//                    HEAD = head->next;
//                head = head->next;
//            } else if (head->next != NULL) {
//                if (head->next->val == val)
//                    head->next = head->next->next;
//                else
//                    head = head->next;
//            } else
//                head = head->next;
//        }
//        return HEAD;
            if (head == NULL) return NULL;
            head->next = removeElements(head->next, val);
            return head->val == val ? head->next : head;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(2);
    ListNode* node4 = new ListNode(1);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    Solution* s = new Solution;
    ListNode* l = s->removeElements(node1, 2);
    return 0;
}
