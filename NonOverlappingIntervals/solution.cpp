#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // To find overlapping intervals we first need to sort
        sort(intervals.begin(), intervals.end());

        const int N = intervals.size();
        const int START = 0;
        const int END = 1;

        vector<int> currInterval = intervals.at(0);
        int deletes = 0;
        for(int i = 1; i < N; ++i) {
            vector<int> nextInterval = intervals.at(i);
            // When we find overlapping intervals, that means that we can perform a delete
            if(currInterval.at(END) > nextInterval.at(START)) {
                // However, keep the min value of both ends, this ensures that we will overlap the 
                // least amount of times
                // Keeping the max value will result in more overlaps, and we want the minimum
                currInterval[END] = min(currInterval[END], nextInterval[END]);
                ++deletes;
            }
            else {
                // If no overlap, grab next interval
                currInterval = nextInterval;
            }
        }

        return deletes;
    }
};