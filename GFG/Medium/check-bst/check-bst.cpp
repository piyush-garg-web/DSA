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
	private:
	bool solve(Node* root, int mini, int maxi) {
		
		if (root == NULL) {
			return true;
		}
		
		if (root->data >= maxi || root->data <= mini) {
			return false;
		}
		
		bool left = solve(root->left, mini, root->data);
		bool right = solve(root->right, root->data, maxi);
		
		return left && right;
	}
	
	public:
	bool isBST(Node* root) {
		
		return solve(root, INT_MIN, INT_MAX);
		
	}
};
