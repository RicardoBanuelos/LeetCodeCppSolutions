#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return nullptr;
        }

        // If node already in map, just return the copy
        if(copies.contains(head)) {
            return copies[head];
        }

        // Map the copy to the original node
        Node* copy = new Node(head->val);
        copies[head] = copy;

        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);

        return copy;
    }

private:
    unordered_map<Node*, Node*> copies;
};