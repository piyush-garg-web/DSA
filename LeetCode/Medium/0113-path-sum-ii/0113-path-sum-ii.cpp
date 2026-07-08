/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int> subans) {
        if (root == NULL) {
            return;
        }

        subans.push_back(root->val);

        if (root->left == NULL && root->right == NULL && targetSum == root->val) {
            ans.push_back(subans);
        }

        solve(root->left, targetSum - root->val, ans, subans);
        solve(root->right, targetSum - root->val, ans, subans);
        subans.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> subans;
        solve(root, targetSum, ans, subans);
        return ans;
    }
};