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
private:
    void solve(TreeNode* root, vector<string>& ans, string temp) {
        temp += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }

        if (root->left) {
            solve(root->left, ans, temp + "->");
        }

        if (root->right) {
            solve(root->right, ans, temp + "->");
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp = "";
        solve(root, ans, temp);
        return ans;
    }
};