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
    TreeNode* buildBST(vector<int>& preorder, int& i, int mini, int maxi, int size) {
        if (i >= size) {
            return NULL;
        }

        if (preorder[i] < mini || preorder[i] > maxi) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = buildBST(preorder, i, mini, root->val, size);
        root->right = buildBST(preorder, i, root->val, maxi, size);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int n = preorder.size();
        TreeNode* ans = buildBST(preorder, i, mini, maxi, n);
        return ans;
    }
};