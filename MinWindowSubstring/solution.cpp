#include <bits/stdc++.h>
using namespace std;

// Sliding window solution

class Solution {
public:
    string minWindow(string s, string t) {
        const int N = s.size();
        const int M = t.size();

        // if t doesnt fit in s just go back
        if(M > N) {
            return "";
        }

        // count how many of each char we need from t
        unordered_map<char, int> tCharCount;
        for(char c : t) {
            ++tCharCount[c];
        }

        int left = 0;

        // count how many chars of t we have to compare with   
        int haveChars = 0;
        const int needChars = tCharCount.size();

        int minSize = INT_MAX;

        // well save the min pointers to not be building substring during our for loop
        int minLeft = 0;
        int minRight = 0;

        for(int right = 0; right < N; ++right) {
            char rightChar = s.at(right);


            if(tCharCount.contains(rightChar)) {
                --tCharCount[rightChar];
                // tCharCount[char] is zero, he have exactly the amount of one char, so we increment haveChars
                if(tCharCount[rightChar] == 0) {
                    ++haveChars;
                }
            }

            // When we match haveChars, we will reduce window, this will allow us to remove unwanted chars
            while(needChars == haveChars) {
                int currSize = right - left + 1;
                if(currSize < minSize) {
                    minSize = currSize;
                    minLeft = left;
                    minRight = right;
                }

                char leftChar = s.at(left);
                if(tCharCount.contains(leftChar)) {
                    ++tCharCount[leftChar];
                    // When tCharCount[char] goes above zero that means we lost a char, so we decrease  haveChars
                    if(tCharCount[leftChar] > 0) {
                        --haveChars;
                    }
                }

                // make window smaller
                ++left;
            }
        }

        // return substring of min ptrs
        return minSize == INT_MAX ? "" : s.substr(minLeft, minSize); 
    }
};