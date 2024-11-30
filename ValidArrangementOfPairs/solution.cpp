#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Well use first as IN and second as OUT
        unordered_map<int, pair<int, int>> inAndOuts;
        unordered_map<int, deque<int>> adjList;

        // Count in and outs, and create adjList
        for(const vector<int>& pair : pairs) {
            const int START = pair[0];
            const int END = pair[1];

            ++inAndOuts[START].second;
            ++inAndOuts[END].first;

            adjList[START].push_back(END);
        }

        // Identify starting node, we borrow ideas from Eurelian Paths
        // An Eurelian Path in a graph visits each Edge exactly once 
        int startingNode = -1;
        for(const auto& [node, degree] : inAndOuts) {
            const int IN = degree.first;
            const int OUT = degree.second;

            // A starting node is identified when it has exactly one more out than ins
            if(IN + 1 == OUT) {
                startingNode = node;
                break;
            }
        }

        // If there is no starting node, select any node from adjList
        if(startingNode == -1) {
            startingNode = adjList.begin()->first;
        }

        vector<int> arrangement;
        // Here we use post order DFS (neigbors first, node second)
        // Due to time complexity being (N + E) (N = nodes, E = edges)
        function<void(int)> dfs = [&](int node) {
            while(!adjList[node].empty()) {
                int nextNode = adjList[node].front();
                // Pop node from deque here, so we dont visit it again
                adjList[node].pop_front();
                dfs(nextNode);
            }

            // Push node once we visit all its children first
            arrangement.push_back(node);
        };

        dfs(startingNode);

        // Convert arrangement to output
        // Reverse we used PostOrder
        reverse(arrangement.begin(), arrangement.end());
        vector<vector<int>> output;
        for(int node : arrangement) {
            if(output.empty()) {
                output.push_back({node});
            } 
            else {
                output.back().push_back(node);
                output.push_back({node});
            }
        }

        output.pop_back();
        return output;  
    }
};