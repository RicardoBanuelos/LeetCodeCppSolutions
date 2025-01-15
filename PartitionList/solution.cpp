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
    ListNode* partition(ListNode* head, int x) {
        if(!head) {
            return nullptr;
        }

        vector<ListNode*> beforeNodes;
        vector<ListNode*> afterNodes;

        // Store all nodes in the order that we find them, but based on X
        while(head) {
            if(head->val < x) {
                beforeNodes.push_back(head);
            }
            else {
                afterNodes.push_back(head);
            }

            head = head->next;
        }


        // Change the next pointer for all before and after nodes, to correct their new order
        const int beforeNodesSize = beforeNodes.size();
        for(int i = 0; i < beforeNodesSize - 1; ++i) {
            beforeNodes.at(i)->next = beforeNodes.at(i + 1);
        }

        const int afterNodesSize = afterNodes.size();
        for(int i = 0; i < afterNodesSize -1; ++i) {
            afterNodes.at(i)->next = afterNodes.at(i + 1);
        }

        // If before empty return after, if after empty, return before
        if(beforeNodes.empty()) {
            return afterNodes.front();
        }

        if(afterNodes.empty()) {
            return beforeNodes.front();
        }
        
        // Make before nodes point to the first after node
        beforeNodes.back()->next = afterNodes.front();

        // Make last after node point to NULL to break any possible cycle
        afterNodes.back()->next = nullptr;
        return beforeNodes.front();
    }
};