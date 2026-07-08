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
    void kSmallest(TreeNode* root, int k, int& ans, int& count) {
        if (root == NULL) {
            return;
        }

        kSmallest(root->left, k, ans, count);
        count++;

        if (count == k) {
            ans = root->val;
            return;
        }

        kSmallest(root->right, k, ans, count);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        kSmallest(root, k, ans, count);
        return ans;
    }
};