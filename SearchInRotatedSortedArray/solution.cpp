#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);

        // Once we find the pivot (min number), just perform a binary search on the two rotated parts of the array

        // Left to Pivot - 1 search
        int leftSearchResult = binarySearch(0, pivot - 1, target, nums);
        if(leftSearchResult != -1) {
            return leftSearchResult;
        }

        // Pivot to End of array
        int rightSearchResult = binarySearch(pivot, nums.size() - 1, target, nums);
        if(rightSearchResult != -1) {
            return rightSearchResult;
        }

        return -1;
    }
private:
    int findPivot(const vector<int>& nums) {
        // The goal of this function is to find the min value of the array
        // Because we know that from that index going forwards the array is sorted
        const int N = nums.size();

        int left = 0;
        int right = N - 1;

        while(left <= right) {
            int middle = (left + right) / 2;

            // If our curr num is bigger than our num at the end
            // that means that means that our min number is more to the right
            if(nums.at(middle) > nums.at(N - 1)) {
                left = middle + 1;
            }
            // If not, we are in the sorted array area, meaning that we have to go back to find our min num
            else {
                right = middle - 1;
            }
        } 

        // Our min num will end at our left pointer
        return left;
    }

    int binarySearch(int left, int right, int target, const vector<int>& nums) {
        while(left <= right) {
            int middle = (left + right) / 2;

            if(nums.at(middle) == target) {
                return middle;
            }

            if(nums.at(middle) < target) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return -1;
    }
};