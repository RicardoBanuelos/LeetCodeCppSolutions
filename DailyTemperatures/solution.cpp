#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int N = temperatures.size();
        vector<int> output(N);

        // We will use a monotonic stack where we will store temperatures in a decreasing order
        // But we will store its indexes, not the temp value, we want the index, to 
        // know where to place the next greater temp
        stack<int> monoStack;

        for(int i = 0; i < N; ++i) {
            int temp = temperatures[i];

            // While our current temp is greater than the one at the top of the stack
            while(!monoStack.empty() && temp > temperatures[monoStack.top()]) {
                int top = monoStack.top();
                monoStack.pop();

                // Top is our index, so we update the index with the temp that we just found
                output[top] = i - top;
            }
            
            // Push current temps index so we can look for a greater temp than it
            monoStack.push(i);
        }

        return output;
    }
};