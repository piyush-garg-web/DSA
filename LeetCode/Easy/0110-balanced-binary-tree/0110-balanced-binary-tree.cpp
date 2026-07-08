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
    pair<bool, int> balanced(TreeNode* root) {
        if (root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> left = balanced(root->left);
        pair<bool, int> right = balanced(root->right);

        bool cond1 = left.first;
        bool cond2 = right.first;
        bool cond3 = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;

        if (cond1 && cond2 && cond3) {
            ans.first = true;
            ans.second = max(left.second, right.second) + 1;
        } else {
            ans.first = false;
            ans.second = max(left.second, right.second) + 1;
        }

        return ans;
    }

public:
    bool isBalanced(TreeNode* root) {
        return balanced(root).first;
    }
};