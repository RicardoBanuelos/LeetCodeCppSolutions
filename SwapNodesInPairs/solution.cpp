#include <bits/stdc++.h>
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

class SolutionIterativeWithVector {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head || !head->next) return head;
        
        // Collect all nodes first
        vector<ListNode*> nodes;
        ListNode* crawler = head;
        
        while(crawler)
        {
            nodes.push_back(crawler);
            crawler = crawler->next;
        }
        
        // Swap in pairs
        const int N = nodes.size();
        for(int i = 0; i + 1 < N; i += 2)
        {
            swap(nodes[i], nodes[i + 1]);
        }
        
        // Since nodes are already ordered as we need them, just make them point to new next one
        for(int i = 0; i < N - 1; ++i)
        {
            nodes[i]->next = nodes[i + 1];
        }
        
        // Add nullptr at the last node
        nodes[N - 1]->next = nullptr;
        
        return nodes[0];    
    }
};

class SolutionRecursive {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        
        ListNode* swappedNext = swapPairs(head->next->next);    
        ListNode* next = head->next;

        head->next = swappedNext;
        next->next = head;
        return next;
    }
};