#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        // The constraint for this problem is O(Log(N)), so we have to use 
        // binary search

        const int N = nums.size();
        int left = 0;
        int right = N - 1;

        // The array is sorted, but rotated, meaning that there is a pivot where the array wil be sorted
        // For example: 
        // [4,5,6,7,0,1,2]
        //          P
        // Our pivot is the minimum number, our answer actually

        while(left <= right) {
            // When we calculate the middle, we can compare it to the last number in the array
            // [4,5,6,7,0,1,2]
            //        M     Last
            // If our middle is greater than our last, 
            // that means that from Left->Middle is sorted
            // and from Middle->Right we should find the min value

            // Other example
            // [4,0,1,2,3]
            //      M    Last
            // the other case is when our middle is not greater than our last
            // meaning that Middle->right is sorted
            // and Left->Middle has the min value
            int middle = (left + right) / 2;
            if(nums.at(middle) > nums.at(N - 1)) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }

        // When we exhaust or search, our min value will always end in the left pointers
        return nums.at(left);
    }
};