
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    // Recursive DFS
    Node* cloneGraph(Node* node) {
        // Always check for nulls when using pointer
        if(!node) {
            return node;
        }
        
        // If we already created a copy of this node, return it
        if(copies.count(node)) {
            return copies[node];
        }
        
        // Create deep copy of node
        copies[node] = new Node(node->val);
        
        // Explore all neighbors and push back into the copies neighbors vector,
        // the function will always return a copy or null
        for(Node* neighbor : node->neighbors) {
            copies[node]->neighbors.push_back(cloneGraph(neighbor));
        }

        // Return the newly created copy
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};