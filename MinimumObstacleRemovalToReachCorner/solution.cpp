#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        const int EMPTY = 0;
        const int OBSTACLE = 1;

        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        const int GOAL_ROW = ROWS - 1;
        const int GOAL_COL = COLS - 1;

        const int DELTAS = 4;
        // Up -> Right -> Down -> Left
        const int deltaRows[DELTAS] = {-1, 0, 1, 0};
        const int deltaCols[DELTAS] = {0, 1, 0, -1};

        function<bool(int, int)> isInBounds = [&](int row, int col) -> bool {
            return row >= 0 && row < ROWS && col >= 0 && col < COLS;
        };

        // CostMap to not add previous visited cells to the minHeap
        vector<vector<int>> costMap(ROWS, vector<int>(COLS, INT_MAX));
        costMap[0][0] = 0;

        // We want the path with the least amount of obstacles at the top, so we create a minHeap
        // This way we always process the path with the least amount of obstacles first
        typedef pair<int, pair<int, int>> costPair;
        priority_queue<costPair, vector<costPair>, greater<costPair>> minHeap;


        // BFS Approach, DFS gives TLE 
        minHeap.push({0, {0, 0}});
        while(!minHeap.empty()) {
            auto [obstacles, coord] = minHeap.top();
            minHeap.pop();

            auto [row, col] = coord;

            if(grid[row][col] == OBSTACLE) {
                ++obstacles;
            }

            // With a BFS, you always reach your goal with the shortest path
            // In this the case the minHeap allowed us to reach with the least amount of obstacles
            // Meaning that we can return as soon as we reach goal
            if(row == GOAL_ROW && col == GOAL_COL) {
                return obstacles;
            }

            for(int i = 0; i < DELTAS; ++i) {
                int newRow = row + deltaRows[i];
                int newCol = col + deltaCols[i];

                if(!isInBounds(newRow, newCol)) {
                    continue;
                }


                // We only add to the minHeap when we reach a cell with less obstacles than it has previously seen
                // This avoids adding unnecessary cells to the heap
                if(obstacles < costMap[newRow][newCol]) {
                    costMap[newRow][newCol] = obstacles;
                    minHeap.push({obstacles, {newRow, newCol}});
                }
            }
        }
        
        return -1;
    }
};