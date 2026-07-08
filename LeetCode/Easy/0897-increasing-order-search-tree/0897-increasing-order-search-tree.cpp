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
    private :
    void inorder(TreeNode* root,vector<int>& nodes) {
        if (root==NULL) {
            return;
        }
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        TreeNode* ans=new TreeNode(nodes[0]);
        TreeNode* temp=ans;
        for (int i=1;i<nodes.size();i++) {
            TreeNode* nextNode=new TreeNode(nodes[i]);
            temp->right=nextNode;
            temp=temp->right;
        }
        return ans;
        
    }
};