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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) {
            return head;
        }

        // Save the amount of nodes we need to reverse
        int nodesToReverse = right - left + 1;

        // Find left node and keep the previous one
        ListNode* prevNode = nullptr;
        ListNode* leftNode = head;
        while(leftNode && --left) {
            prevNode = leftNode;
            leftNode = leftNode->next;
        }

        // Reverse list, we need head and tail of rev list
        ReverseListData revListData = reverseList(leftNode, nodesToReverse);

        // If prevNode exists, point it to the head of reverse list
        // If it doesnt exist it mean revListData.head is the head, meaning left was 1
        if(prevNode) {
            prevNode->next = revListData.head;
        }

        return prevNode ? head : revListData.head;
    }
private: 
    struct ReverseListData {
        ReverseListData() {

        }

        ListNode* head;
        ListNode* tail;
    };

    ReverseListData reverseList(ListNode* head, int nodesToReverse) {
        ListNode* prev = nullptr;
        // the first node we receive is going to be the new tail
        ListNode* tail = head;
        ListNode* curr = head;


        // Reversing list starting from head, and only reversing the int we receive
        while(curr && nodesToReverse--) {
            ListNode* next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // curr is the next node that was supposed to reverse, so we point the tail to it
        tail->next = curr;

        ReverseListData revListData;
        revListData.head = prev;
        revListData.tail = tail;

        return revListData;
    }
};