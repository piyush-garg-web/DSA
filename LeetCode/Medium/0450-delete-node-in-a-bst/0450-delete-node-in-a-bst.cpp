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
    int minimum(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->left != NULL) {
            temp = temp -> left;
        }

        return temp->val;
    }

    TreeNode* deleting(TreeNode* root, int key) {

           if (root == NULL) {
            return root;
        }

        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            if (root->left != NULL && root->right != NULL) {

                int mini = minimum(root->right);
                root->val = mini;
                root->right = deleting (root->right, mini);
                return root;
            }
        } else if (root->val > key) {
            root->left = deleting (root->left, key);
            return root;
        } else {
            root->right = deleting (root->right, key);
            return root;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
     
        TreeNode* finalAns = deleting (root, key);
        return finalAns;
    }
};