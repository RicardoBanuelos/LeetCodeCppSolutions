#include<bits/stdc++.h>
using namespace std;

// Memoization solution 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int N = s.size();

        // At every index we finish processing, store result, to not process it again
        vector<int> memo(N, -1);

        // Solve problem with basic backtracking, going forward when curr word matches a substring of s
        function<bool(int)> backtracking = [&](int i) -> bool {
            if(i >= s.size()) {
                return true;
            }

            if(memo[i] != -1) {
                return memo[i];
            }

            for(const string& word : wordDict) {
                int wordSize = word.size();

                // If word doesnt fit
                if((i + wordSize - 1) >= s.size()) {
                    continue;
                }

                // If word doesnt match substring of size wordSize
                if(word != s.substr(i, wordSize)) {
                    continue;
                }

                // Check if backtracking returns true to stop for loop
                if(backtracking(i + wordSize)) {
                    return memo[i] = true;
                }
            }

            return memo[i] = false;
        };

        return backtracking(0);
    }
};