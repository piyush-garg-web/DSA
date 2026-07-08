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
    void inorder(TreeNode* root,vector<int>& subans) {
        if (root==NULL) {
            return;
        }
        inorder(root->left,subans);
        subans.push_back(root->val);
        inorder(root->right,subans);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> subans1;
        vector<int> subans2;
        inorder(root1,subans1);
        inorder(root2,subans2);
        vector<int> ans;
        int m=subans1.size();
        int n=subans2.size();
        int i=0;
        int j=0;

        while (i<m && j<n) {
            if (subans1[i]<=subans2[j]) {
ans.push_back(subans1[i]);
i++;
            }
            else {
                ans.push_back(subans2[j]);
                j++;
            }
        }

        while (i<m) {
            ans.push_back(subans1[i]);
            i++;
        }
        while (j<n) {
            ans.push_back(subans2[j]);
            j++;
        }

        return ans;

        
    }
};