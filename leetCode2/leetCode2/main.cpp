//
//  main.cpp
//  leetCode2
//
//  Created by 张傲天 on 2016/12/26.
//  Copyright © 2016年 张傲天. All rights reserved.
//
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * reverseList(ListNode * head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode* new_tail=reverseList(head->next);
    head->next->next=head;
    head->next=NULL;
    return new_tail; //输出: 新链表的尾指针？》？
}
void displayList(ListNode * head) {
    while (head != NULL) {
        cout<<head->val;
        head = head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * rl1 = reverseList(l1);
        ListNode * rl2 = reverseList(l2);
        
        ListNode * number = new ListNode(0);
        ListNode * head = number;
        int jinwei = 0;
        cout<<"rl1:";displayList(rl1);
        cout<<"rl2:";displayList(rl2);
        while (rl1 != NULL || rl2 != NULL || jinwei != 0) {
            int n1 = 0,n2 = 0;
            if (rl1 != NULL) {
                n1 = rl1->val;
                rl1 = rl1->next;
            }
            if (rl2 != NULL) {
                n2 = rl2->val;
                rl2 = rl2->next;
            }
            number->val = (n1 + n2 + jinwei) % 10;
            jinwei = (n1+ n2 + jinwei)/10;
            
            number->next = new ListNode(0);
            number = number->next;
        }
        
        return reverseList(head)->next;
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    ListNode * node1 = new ListNode (5);
    ListNode * node2 = new ListNode (6);
    ListNode * node3 = new ListNode (4);
    
    ListNode * node4 = new ListNode (9);
    
    node1->next = node2;
    node2->next = node3;
    
    Solution * s = new Solution;
    
    ListNode * number = s->addTwoNumbers(node1, node4);
    displayList(number);
    
    return 0;
}
