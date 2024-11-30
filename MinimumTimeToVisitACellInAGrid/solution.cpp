#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // This is the only case when we cant reach our goal
        if(grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        function<bool(int, int)> isInBounds = [&](int row, int col) -> bool {
            return row >= 0 && row < ROWS && col >= 0 && col < COLS;
        };

        const int GOAL_ROW = ROWS - 1;
        const int GOAL_COL = COLS - 1;

        const int VISITED = INT_MAX;

        const int DELTAS = 4;
        // Up -> Right -> Down -> Left
        const int deltaRows[DELTAS] = {-1, 0, 1, 0};
        const int deltaCols[DELTAS] = {0, 1, 0, -1};

        // Min Heap to process the cells with the least amount of time first 
        typedef pair<int, pair<int, int>> timePair;
        priority_queue<timePair, vector<timePair>, greater<timePair>> minHeap;
        minHeap.push({0, {0, 0}});
        grid[0][0] = VISITED;
        
        while(!minHeap.empty()) {
            auto [time, coord] = minHeap.top();
            auto [row, col] = coord;
            minHeap.pop();

            // Since we use BFS, as soon as we hit the goal, we can returm the time
            if(row == GOAL_ROW && col == GOAL_COL) {
                return time;
            }

            for(int i = 0; i < DELTAS; ++i) {
                int newRow = row + deltaRows[i]; 
                int newCol = col + deltaCols[i];

                if(!isInBounds(newRow, newCol)) {
                    continue;
                }

                if(grid[newRow][newCol] == VISITED) {
                    continue;
                }

                // Here we need to know how much time we need to waste to reach the next cell
                int diff = grid[newRow][newCol] - time;
                // No need to waste time
                if(diff <= 1) {
                    minHeap.push({time + 1, {newRow, newCol}});
                }
                // If diff is uneven, we can reach the cell at the exact time it requires
                else if(diff % 2) {
                    minHeap.push({grid[newRow][newCol], {newRow, newCol}});
                } 
                // If diff is even, we can reach the cell at the time it requires + 1
                else {
                    minHeap.push({grid[newRow][newCol] + 1, {newRow, newCol}});
                }

                // Mark as visited to avoid looping
                grid[newRow][newCol] = VISITED;
            }
        }

        return -1;
    }
};