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
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

    TreeNode* buildBST(int s, int e, vector<int>& nodes) {
        if (s > e) {
            return NULL;
        }

        int mid = s + ((e - s)) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildBST(s, mid - 1, nodes);
        root->right = buildBST(mid + 1, e, nodes);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        TreeNode* ans = buildBST(0, nodes.size() - 1, nodes);
        return ans;
    }
};