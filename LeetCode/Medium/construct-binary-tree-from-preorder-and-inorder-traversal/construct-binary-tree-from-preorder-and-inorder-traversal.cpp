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

    TreeNode* solve(map<int, int>& mapping, int size, vector<int>& preorder,
                    vector<int>& inorder, int& preorderIndex, int inorderStart,
                    int inorderEnd) {
        if (preorderIndex >= size || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(element);
        int position = mapping[element];
        root->left = solve(mapping, size, preorder, inorder, preorderIndex,
                           inorderStart, position - 1);
        root->right = solve(mapping, size, preorder, inorder, preorderIndex,
                            position + 1, inorderEnd);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int preorderIndex = 0;
        map<int, int> mapping;
        createMap(mapping, size, inorder);
        TreeNode* root = solve(mapping, size, preorder, inorder, preorderIndex, 0, size - 1);
        return root;
    }
};