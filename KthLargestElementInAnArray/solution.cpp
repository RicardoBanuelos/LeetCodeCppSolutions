#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // We will use a MinHeap to solve this problem,
        // A min heap will always have our min value at the top
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int n : nums) {
            // Push value, minHeap sorts the data, keeping min value always at the top
            minHeap.push(n);
            
            // When we exceed the Kth elements we need, we pop
            if(minHeap.size() > k) {
                // It will always pop the min value, meaning that we have the K largest 
                // in the heap
                minHeap.pop();
            }
        }


        // Our min value will be our Kth value, which is at the top of the heap
        return minHeap.top();
    }
};