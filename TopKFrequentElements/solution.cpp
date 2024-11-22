#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // first we use a map to get the frequence of each num  
        // key -> num
        // value -> frequency
        unordered_map<int, int> numCount;
        for(int n : nums) {
            ++numCount[n];
        }

        // We create a minHeap to keep the number with the smallest frequency at the top
        // We will use a pair to store the data 
        // first = frequency
        // second = num
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto& [num, count] : numCount) {
            minHeap.push({count, num});
            // When our heap exceeds the K amount we need, we pop
            if(minHeap.size() > k) {
                // Our element with the current min frequency will be popped
                minHeap.pop();
            }
        }

        vector<int> elements;
        while(!minHeap.empty()) {
            // Only push second element into vector, because or secon element is our number
            // not our frequency
            elements.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return elements;
    }
};