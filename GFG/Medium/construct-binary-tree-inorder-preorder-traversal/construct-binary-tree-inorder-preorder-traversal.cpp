class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; 

class Solution {
	private:
	Node* build (vector<int> &inorder, vector<int> &preorder, int preStart, int preEnd, int inStart, int inEnd,
	unordered_map<int, int>& mp) {
		
		if (preStart>preEnd) {
			return NULL;
		}
		
		Node* root = new Node(preorder[preStart]);
		
		int value = mp[preorder[preStart]];
		int left = value - inStart;
		
		root->left = build(inorder, preorder, preStart + 1, preStart + left, inStart, value - 1, mp);
		root->right = build(inorder, preorder, preStart + left + 1, preEnd, value + 1, inEnd, mp);
		
		return root;
		
	}
	
	public:
	Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
		
		unordered_map<int, int> mp;
		
		for (int i = 0; i<inorder.size(); i++) {
			mp[inorder[i]] = i;
		}
		
		return build (inorder, preorder, 0, preorder.size() - 1, 0, inorder.size() - 1, mp);
		
	}
};
