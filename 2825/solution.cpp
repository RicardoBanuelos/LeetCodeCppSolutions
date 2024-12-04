#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        const int N = str1.size();
        const int M = str2.size();

        // Pointer to keep track of which char in str2 we need
        int currChar = 0;
        for(int i = 0; i < N && currChar < M; ++i) {
            // We continue when even with cycling we dont obtain currChar
            if(str1[i] != str2[currChar] && sumChar(str1[i]) != str2[currChar]) {
                continue;
            }

            // We point to the next char
            ++currChar;
        }

        // We know we obtained the desired string when currChar is out of bounds
        return currChar == M;
    }

private:
    // Quick helper function to "cycle" the chars
    char sumChar(char c) {
        return (c + 1) > 'z' ? 'a' : c + 1;
    }
};