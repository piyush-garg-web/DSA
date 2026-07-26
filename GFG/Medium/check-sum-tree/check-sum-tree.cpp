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
	pair<bool, int> solve (Node* node) {
		
		if (node == NULL) {
			return {true, 0};
		}
		
		if (node->left == NULL && node->right == NULL) {
			return {true, node->data};
		}
		
		auto left = solve(node->left);
		auto right = solve(node->right);
		
		bool isSumTree = left.first && right.first && (node->data == left.second + right.second);
		
		int totalSum = left.second + right.second + node->data;
		
		return {isSumTree, totalSum};
	}
	
	public:
	bool isSumTree(Node* node) {
		
		return solve(node).first;
		
	}
};
