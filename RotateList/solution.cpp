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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) {
            return nullptr;
        }

        // Count nodes and find tail
        int nodes = 1;
        ListNode* oldTail = head;
        while(oldTail->next) {
            ++nodes;
            oldTail = oldTail->next;
        }

        // Connect tail to head to create circular linked list
        // This will help us rotate the head to its new position
        oldTail->next = head;

        // This will reduce rotations if K > nodes
        k %= nodes;

        // Steps needed to reach new head, new head will be at N - K
        int newHeadSteps = nodes - k;

        // New tail will always be behind head, it will act as previous node
        ListNode* newTail = nullptr;
        while(newHeadSteps) {
            newTail = head;
            head = head->next;

            --newHeadSteps;
        }


        // Once head is at new position, break circular linked list by pointing next ptr to null
        newTail->next = nullptr;
        return head;
    }   
};