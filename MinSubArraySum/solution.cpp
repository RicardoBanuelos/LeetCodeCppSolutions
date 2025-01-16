#include<bits/stdc++.h>
using namespace std;

// Sliding Window Solution
// Add with right pointer, subtract with left pointer

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int N = nums.size();

        int sum = 0;
        int left = 0;
        int minLength = INT_MAX;

        for(int right = 0; right < N; ++right) {
            // Add to sum with right ptr
            sum += nums.at(right);

            // If sum meets reqs, evaluate length of window
            while(sum >= target) {
                int currLength = right - left + 1;
                minLength = min(minLength, currLength);

                // Reduce and reduce window, since were looking for min subarray
                sum -= nums.at(left);
                ++left;
            }
        }

        // If minLength == INT_MAX sum never reached the target
        return minLength == INT_MAX ? 0 : minLength;
    }
};