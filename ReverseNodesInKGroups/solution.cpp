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
    ListNode* reverseKGroup(ListNode* head, int k) {
        const int N = countNodes(head);
        const int REVERSES = N / k;
        
        if(N < k) {
            return head;
        }

        ReversedList revList = reverseList(head, k);
        ListNode* newHead = revList.head;
        ListNode* tail = revList.tail;
        ListNode* nextToRev = tail->next;

        for(int i = 1; i < REVERSES; ++i) {
            ReversedList revList = reverseList(nextToRev, k);
            tail->next = revList.head;
            tail = revList.tail;
            nextToRev = tail->next;
        }

        return newHead;
    }

private:
    struct ReversedList {
        ReversedList() {}
        ListNode* head;
        ListNode* tail;
    };

    int countNodes(ListNode* head) {
        int count = 0;

        while(head) {
            head = head->next;
            ++count;
        }

        return count;
    }

    ReversedList reverseList(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* tail = head;

        while(curr && k--) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        tail->next = curr;

        ReversedList reversedList;
        reversedList.head = prev;
        reversedList.tail = tail;

        return reversedList;
    }
};