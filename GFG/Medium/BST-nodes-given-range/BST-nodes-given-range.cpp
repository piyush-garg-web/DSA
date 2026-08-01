class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	// Constructor to initialize a new node
	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};

class Solution {
	private:
	int solve (Node* root, int l, int h) {
		
		if (root == NULL) {
			return 0;
		}
		
		if (root->data<l) {
			return solve(root->right, l, h);
		}
		
		if (root->data>h) {
			return solve(root->left, l, h);
		}
		
		return 1 + solve(root->left, l, h) + solve(root->right, l, h);
	}
	public:
	int getCount(Node *root, int l, int h) {
		
		return solve (root, l, h);
		
	}
};
