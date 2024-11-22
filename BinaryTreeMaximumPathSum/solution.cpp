#include<bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        // Recursive Function to sum all paths
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if(!node) {
                return 0;
            }

            // Explore DFS style, we grab max of recursive function or 0, 
            // because we dont want any negatives
            int leftMax = max(dfs(node->left), 0);
            int rightMax = max(dfs(node->right), 0);

            // Our current sum will be value of our node, and whatever max values we found 
            // on our left and right paths
            maxSum = max(maxSum, node->val + leftMax + rightMax);

            // To be able to sum this path when we return, we can only sum
            // our node plus our left or right path, not both, so we return the max of left and right
            return node->val + max(leftMax, rightMax);
        };

        dfs(root);
        return maxSum;
    }
};