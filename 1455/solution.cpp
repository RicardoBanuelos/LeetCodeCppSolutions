#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words = tokenize(sentence);

        const int N = words.size();
        const int M = searchWord.size();

        for(int i = 0; i < N; ++i) {
            string word = words[i];
            if(word.size() < M) {
                continue;
            }

            // We dont know if word is bigger than searchword so we just 
            // grab a substring of size M
            if(word.substr(0, M) == searchWord) {
                return i + 1;
            }
        }

        return -1;
    }

private:
    // function to get tokens from string, delimiter is ' ' (a space)
    vector<string> tokenize(const string& s) {
        vector<string> tokens;

        stringstream ss(s);
        string token;
        while(getline(ss, token, ' ')) {
            tokens.push_back(token);
        }

        return tokens;
    }
};