#include <bits/stdc++.h>
using namespace std;

// Sliding Window Solution

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.size();

        // use map to count char occurences
        unordered_map<char, int> charCount;

        // Left ptr to decrease chars at left
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < N; ++right) {
            // Right ptr will increase chars
            char rightChar = s.at(right);
            ++charCount[rightChar];

            // Fix window until we only have one occurrence of current char we just added
            while(charCount[rightChar] > 1) {
                --charCount[s.at(left)];
                ++left;
            }

            // Update max lenght
            int currLength = right - left + 1;
            maxLength = max(maxLength, currLength);
        }

        return maxLength;
    }
};