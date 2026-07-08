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
    void createMap(map<int, int>& mapping, int size, vector<int>& inorder) {
        for (int i = 0; i < size; i++) {
            mapping[inorder[i]] = i;
        }
    }

    TreeNode* solve(map<int, int>& mapping, int size, vector<int>& postorder,
                    vector<int>& inorder, int& postorderIndex, int inorderStart,
                    int inorderEnd) {
        if (postorderIndex < 0 || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(element);
        int position = mapping[element];
        root->right = solve(mapping, size, postorder, inorder, postorderIndex,
                            position + 1, inorderEnd);
        root->left = solve(mapping, size, postorder, inorder, postorderIndex,
                           inorderStart, position - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        int postorderIndex = size - 1;
        map<int, int> mapping;
        createMap(mapping, size, inorder);
        TreeNode* root = solve(mapping, size, postorder, inorder, postorderIndex, 0, size - 1);
        return root;
    }
};