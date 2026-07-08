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
    void inorder(TreeNode* root, vector<int>& ans, int &freq, int& maxFreq, int& curr) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, ans, freq, maxFreq, curr);

        if (root->val == curr) {
            freq++;
        } else {
            curr = root->val;
            freq = 1;
        }

        if (freq > maxFreq) {
            maxFreq = freq;
            ans.clear();
            ans.push_back(curr);
        } else if (freq == maxFreq) {
            ans.push_back(curr);
        }

        inorder(root->right, ans, freq, maxFreq, curr);
    }

public:
    vector<int> findMode(TreeNode* root) {
        int freq = 0;
        int maxFreq = 0;
        int curr = INT_MIN;
        vector<int> ans;
        inorder(root, ans, freq, maxFreq, curr);
        return ans;
    }
};