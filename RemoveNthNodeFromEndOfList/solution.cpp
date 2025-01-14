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

            // Travel to end, return curr if N is not zero, return next if N = 0
            ListNode* next = worker(head->next);

            // Decrease N every time we return
            --n;

            // N will only be 0 exactly once
            if(n == 0) {
                // Avoid this node, return its next
                return next;
            }

            // Point curr node to the next node we received from recursion
            head->next = next;
            return head;
        };

        return worker(head);
    }
};