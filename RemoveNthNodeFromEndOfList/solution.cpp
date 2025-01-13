#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        function<ListNode*(ListNode*)> worker = [&](ListNode* head) -> ListNode* {
            if(!head) {
                return nullptr;
            }

            ListNode* next = worker(head->next);
            --n;

            if(n == 0) {
                return next;
            }

            head->next = next;
            return head;
        };

        return worker(head);
    }
};