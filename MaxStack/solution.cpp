#include<bits/stdc++.h>
using namespace std;

class MaxStack {
public:
    MaxStack() 
    {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    void push(int x) 
    {
        // Create a new Node, add to doubly linked list at tail
        // And add to map based on value of 'x'

        Node* newNode = new Node(x);

        addNode(newNode);
        nodes[x].push(newNode);
    }
    
    int pop() 
    {
        // Grab last value added
        int topValue = top();
        
        // Grab last noded added with topValue and pop it
        Node* nodeToDelete = nodes[topValue].top ();
        nodes[topValue].pop();

        // remove key if the stack no longer has nodes
        if(nodes[topValue].empty())
            nodes.erase(topValue);

        removeNode(nodeToDelete);

        delete nodeToDelete;
        return topValue;
    }
    
    int top() 
    {
        // tail prev pointer points to last node added
        return tail->prev->data;
    }
    
    int peekMax() 
    {
        // rbegin gives us a pointer to the last element added to the map, remember that map is ordered, so last element is max
        auto lastElement = nodes.rbegin();
        return lastElement->first;
    }
    
    int popMax() 
    {
        // same as pop but we delete last max value instead of last value added
        int max = peekMax();

        Node* nodeToDelete = nodes[max].top();
        nodes[max].pop();

        if(nodes[max].empty())
            nodes.erase(max);

        removeNode(nodeToDelete);

        delete nodeToDelete;
        return max;
    }

private:
    struct Node {
        Node()
        {
            data = 0;
            next = nullptr;
            prev = nullptr;
        }

        Node(int data)
        {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }

        int data;
        Node* next;
        Node* prev;
    };

    // Sentinel Nodes for our doubly linked list (dummy nodes)
    // Our doubly linked list will keep track of our data as we push or pop 
    Node* head;
    Node* tail;

    // with this data structure we will keep track of max values, since the map orders by the key (int in this case)
    // the stack will let us know what node was pushed last, that way we know what node to delete
    map<int, stack<Node*>> nodes;

    void addNode(Node* newNode)
    {
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        newNode->next = tail;
        tail->prev = newNode;
    }

    void removeNode(Node* nodeToRemove)
    {
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
    }
};