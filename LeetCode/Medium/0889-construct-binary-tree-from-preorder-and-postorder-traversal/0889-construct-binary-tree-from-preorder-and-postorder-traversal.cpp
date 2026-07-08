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

    void createMap (map<int,int> &mapping,vector<int>& postorder,int size) {
for (int i=0;i<size;i++) {
    mapping[postorder[i]]=i;
}
    }

    TreeNode* build(vector<int>& preorder, vector<int>& postorder,int i1,int i2,int j1,int j2,map<int,int>& mapping) {
        if (i1>i2 || j1>j2) {
            return NULL;
        }

        TreeNode* root=new TreeNode(preorder[i1]);
        if (i1==i2) {
            return root;
        }

        int a=mapping[preorder[i1+1]];
        int b=a-j1+1;

        root->left=build(preorder,postorder,i1+1,i1+b,j1,a,mapping);
        root->right=build(preorder,postorder,i1+b+1,i2,a+1,j2-1,mapping);
        return root;


    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        map<int,int> mapping;
        createMap(mapping,postorder,n);
        TreeNode* root=build(preorder,postorder,0,n-1,0,n-1,mapping);
        return root;
        
    }
};