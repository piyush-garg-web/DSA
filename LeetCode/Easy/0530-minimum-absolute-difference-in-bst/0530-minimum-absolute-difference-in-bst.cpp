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
    void mini(TreeNode* root, int &prev, int& ans) {
        if (root == NULL) {
            return;
        }

        mini(root->left, prev, ans);

        if (prev != -1) {
            ans = min(ans, root->val - prev);
        }

        prev = root->val;
        mini(root->right, prev, ans);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        mini(root, prev, ans);
        return ans;
    }
};