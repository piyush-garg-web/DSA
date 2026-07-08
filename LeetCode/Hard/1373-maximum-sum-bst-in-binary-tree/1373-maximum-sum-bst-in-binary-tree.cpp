/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    class info {
    public:
        int sum;
        bool isBST;
        int mini;
        int maxi;
    };

public:
    info solve(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return {0, true, INT_MAX, INT_MIN};
        }

        info left = solve(root->left, maxSum);
        info right = solve(root->right, maxSum);
        info currNode;
        currNode.sum = left.sum + right.sum + root->val;
        currNode.mini = min(root->val, left.mini);
        currNode.maxi = max(root->val, right.maxi);
        if (left.isBST && right.isBST &&
            (root->val > left.maxi && root->val < right.mini)) {
            currNode.isBST = true;
        } else {
            currNode.isBST = false;
        }

        if (currNode.isBST) {
            maxSum = max(maxSum, currNode.sum);
        }

        return currNode;
    }

public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        info ans = solve(root, maxSum);
        return maxSum;
    }
};