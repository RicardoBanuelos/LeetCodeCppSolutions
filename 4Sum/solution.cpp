#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> answer;

        const int N = nums.size();

        // Sort the input array so we can use the two pointers method in the WHILE loop 
        sort(nums.begin(), nums.end());

        // Use this FOR loop to select our first number
        for(int i = 0; i < N - 3; ++i)
        {
            // We skip while nums[i] == nums[i - 1] to avoid duplicates
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int firstNum = nums[i];

            // Use this FOR loop to select our second number
            for(int j = i + 1; j < N - 2; ++j)
            {
                // We skip while nums[j] == nums[j - 1] to avoid duplicates
                if(j > (i + 1) && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int secondNum = nums[j];

                int left = j + 1;
                int right = N - 1;

                // Use a while loop on the rest of the array [j + 1, N - 1]
                // We increment LEFT pointer when sum is equal or lesser than target
                // We decrement RIGHT pointer when sum is greater than target
                while(left < right)
                {
                    int thirdNum = nums[left];
                    int fourthNum = nums[right];

                    long long sum = (long long)firstNum 
                                  + (long long)secondNum 
                                  + (long long)thirdNum 
                                  + (long long)fourthNum;

                    if(sum == target)
                    {
                        answer.push_back({firstNum, secondNum, thirdNum, fourthNum});
                    }

                    if(sum > target)
                    {
                        --right;
                    }
                    // This else is when sum equals target
                    else
                    {
                        ++left;
                        // Increment left while nums[left] == nums[left - 1] to avoid duplicates
                        while(left < right && nums[left] == nums[left - 1])
                        {
                            ++left;
                        }
                    }
                }   
            }
        }

        return answer;
    }
};