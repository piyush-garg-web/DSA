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
	pair<bool, int> solve(Node* root) {
		
		if (root == NULL) {
			return {true, -1};
		}
		
		auto left = solve(root->left);
		auto right = solve(root->right);
		
		bool isBalanced = left.first && right.first && abs(left.second - right.second) <= 1;
		int height = 1 + max(left.second, right.second);
		
		return {isBalanced, height};
		
	}
	
	public:
	bool isBalanced(Node* root) {
		
		return solve(root).first;
		
	}
};
