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
    bool isValid(TreeNode* root, long long min,long long max) {
        if (root==NULL) {
            return true;
        }

        if (root->val>min && root->val<max) {
            bool left=isValid(root->left,min,root->val);
            bool right=isValid(root->right,root->val,max);
            return left && right;
        }
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long min=LLONG_MIN;
        long long max=LLONG_MAX;
        bool ans= isValid(root,min,max);
        return ans;
    }
};