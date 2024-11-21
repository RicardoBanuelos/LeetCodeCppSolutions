#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // For each row, we will perform a binary search
        for(const vector<int>& row : matrix) {
            int left = 0;
            int right = row.size() - 1;    

            // Just treat each row as single dimension array and perform a Binary Search
            while(left <= right) {
                int middle = (left + right) / 2;

                if(row.at(middle) == target) {
                    return true;
                }

                if(row.at(middle) < target) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
            }
        }

        return false;
    }
};