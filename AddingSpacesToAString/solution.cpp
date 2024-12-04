#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // spaces is sorted, so just keep a pointer at the space we need to add
        int nextSpace = 0;
        string output;

        const int N = s.size();
        const int M = spaces.size();

        for(int i = 0; i < N; ++i) {
            // Watch out for nextSpace being >= to M
            // just add a space to output when i matches nextSpace
            if(nextSpace < M && spaces[nextSpace] == i) {
                output.push_back(' ');
                ++nextSpace;
            }
            output.push_back(s[i]);
        }

        return output;
    }
};