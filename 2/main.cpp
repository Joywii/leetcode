//
//  main.cpp
//  Test
//
//  Created by joywii on 15/4/23.
//  Copyright (c) 2015年 sohu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int temp = 0;
        ListNode *t1 = l1, *t2 = l2, *t3 = NULL,*head = NULL;
        while (t1 != NULL && t2 != NULL) {
            int sum = t1->val + t2->val + temp;
            ListNode *t = new ListNode(sum % 10);
            t->next = NULL;
            temp = sum / 10;
            if (head == NULL) {
                head = t;
                t3 = t;
            } else {
                t3->next = t;
                t3 = t;
            }
            
            t1 = t1->next;
            t2 = t2->next;
        }
        while (t1 != NULL) {
            int sum = t1->val + temp;
            ListNode *t = new ListNode(sum % 10);
            t->next = NULL;
            temp = sum / 10;
            if (head == NULL) {
                head = t;
                t3 = t;
            } else {
                t3->next = t;
                t3 = t;
            }
            t1 = t1->next;
        }
        while (t2 != NULL) {
            int sum = t2->val + temp;
            ListNode *t = new ListNode(sum % 10);
            t->next = NULL;
            temp = sum / 10;
            if (head == NULL) {
                head = t;
                t3 = t;
            } else {
                t3->next = t;
                t3 = t;
            }
            t2 = t2->next;
        }
        if (temp != 0) {
            ListNode *t = new ListNode(temp);
            t->next = NULL;
            t3->next = t;
        }
        return head;
    }
    
};
int main(int argc, const char * argv[]) {
    
//    Solution sohution;
    
    return 0;
}