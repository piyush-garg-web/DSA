class Node {
	public:
	int data;
	Node *left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; 

class Solution {
	private:
	struct Info {
		int size;
		int mini;
		int maxi;
	};
	
	Info solve (Node* root) {
		
		if (root == NULL) {
			
			return {0, INT_MAX, INT_MIN};
		}
		
		auto left = solve(root->left);
		auto right = solve(root->right);
		
		if (root->data > left.maxi && root->data < right.mini) {
			return {left.size + right.size + 1, min(root->data, left.mini), max(root->data, right.maxi)};
		}
		
		return {max(left.size, right.size), INT_MIN, INT_MAX};
		
	}
	
	public:
	int largestBst(Node *root) {
		
		return solve (root).size;
		
	}
};