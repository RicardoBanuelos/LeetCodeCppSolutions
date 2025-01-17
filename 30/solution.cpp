#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // Count how many of each word we have
        unordered_map<string, int> wordCount;
        for(string word : words) {
            ++wordCount[word];
        }

        const int N = s.size();
        int wordSize = words[0].size();
        int permSize = wordSize * words.size();

        // Set to not compute perms seen before
        unordered_set<string> seenPerms;

        // Try to build substring with words in wordCount
        function<bool(string&)> canBuild = [&](string& str) -> bool {
            if(seenPerms.contains(str)) {
                return true;
            }

            unordered_map<string, int> wordCountCopy = wordCount;

            for(int i = 0; i < str.size(); i+= wordSize) {
                string subString = str.substr(i, wordSize);
                // wordCount must be more than 0, else just means that we cant no longer use that word
                if(!wordCount.contains(subString) || wordCountCopy[subString] <= 0) {
                    return false;
                }

                --wordCountCopy[subString];
            }   

            // Save valid perm
            seenPerms.insert(str);
            return true;
        };

        // Call can build for every index
        vector<int> output;
        for(int i = 0; i <= N - permSize; ++i ) {
            string subString = s.substr(i, permSize);
            if(canBuild(subString)) {
                output.push_back(i);
            }
        }

        return output;
    }
};