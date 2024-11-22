#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // We will use a monotonick stack, 
        // This stack can either have its data strictly increasing or decreasing
        // In this problem, since we are looking for greater, 
        // we will have our data in decreasing order
        stack<int> monotonicStack;
        // In this map we will just store, our num and the first greater value we find
        // key = num
        // value = greater value we find
        unordered_map<int, int> nextGreater;
        for(int n : nums2) {
            // we will remove from the stack until we empty it or find a value greater than n
            while(!monotonicStack.empty() && n > monotonicStack.top()) {
                int top = monotonicStack.top();
                monotonicStack.pop();
                // the value we pop is an already seen num, so we pop it, and store n as its next greater element
                nextGreater[top] = n;
            }
            // push current value to look for its greater element in the future
            monotonicStack.push(n);
        }

        const int N = nums1.size();
        for(int i = 0; i < N; ++i) {
            // Just traverse the subset and check if value exists in the map
            // if it does set the value we stored in the prev loop
            // if not just set to -1
            if(nextGreater.count(nums1[i]) == 0) {
                nums1[i] = -1;
            }
            else {
                nums1[i] = nextGreater[nums1[i]];
            }
        }

        return nums1;
    }
};