#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        mCapacity = capacity;

        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    // check map if exists
    // remove node from curr position and place at end to update LRU
    int get(int key) {
        if(!keyMap.contains(key)) {
            return -1;
        }

        Node* node = keyMap[key];
        remove(node);
        insert(node);

        return node->value;
    }
    
    // if node exists remove it first
    // place at end
    // if lru is bigger than capacity, remove node at start to update LRU
    void put(int key, int value) {
        if(keyMap.contains(key)) {
            remove(keyMap[key]);
        }

        Node* node = new Node(key, value);
        insert(node);
        keyMap[key] = node;

        if(keyMap.size() > mCapacity) {
            Node* leastUsedNode = head->next;
            remove(leastUsedNode);
            keyMap.erase(leastUsedNode->key);
        }
    }

private:

    // Doubly Linked List
    struct Node {
        Node() {
            prev = nullptr;
            next = nullptr;
        }

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }

        Node* prev;
        Node* next;
        int key;
        int value;
    };


    // Sentinel node to remove from start (head)
    // and (Tail) to insert at end
    Node* head;
    Node* tail;
    int mCapacity;

    // Map to find nodes based on their key values
    unordered_map<int, Node*> keyMap;

    // Use tail to insert at end
    void insert(Node* node) {
        node->prev = tail->prev;
        node->next = tail;

        tail->prev->next = node;
        tail->prev = node;
    }


    // Use head to remove from start
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};