#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long minBananas = 1;
        long long maxBananas = *max_element(piles.begin(), piles.end());

        int output = maxBananas;

        // Binary Search to select the eating speed
        while(minBananas <= maxBananas) {
            long long eatingSpeed  = (minBananas + maxBananas) / 2;

            //Try to eat all bananas with current speed
            long long hours = hoursToEatAllBananas(eatingSpeed, piles);

            // If we achieve to eat all bananas, try to eat with less speed
            if(hours <= h) {
                output = eatingSpeed;
                maxBananas = eatingSpeed - 1;
            }
            // Else try to eat more bananas
            else {
                minBananas = eatingSpeed + 1;
            }
        }

        return output;
    }

private:
    long long hoursToEatAllBananas(long long eatingSpeed, const vector<int>& piles) {

        long long hours = 0;

        for(long long bananas : piles) {
            long long currentHours = bananas / eatingSpeed;
            // If there are leftovers that takes another hour
            currentHours += bananas % eatingSpeed > 0 ? 1 : 0;

            hours += currentHours;
        }

        return hours;
    }
};