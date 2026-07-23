class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};

class Solution {
	public:
	int height(Node* root) {
		
		if (root == NULL) {
			return - 1;
		}
		
		int leftSubtree = 1 + height(root->left);
		int rightSubtree = 1 + height(root->right);
		
		return max(leftSubtree, rightSubtree);
		
	}
};
