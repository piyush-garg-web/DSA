class Node {
	public:
	int data;
	Node* left;
	Node* right;
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

class Solution {
	private:
	pair<int, int> solve (Node* root) {
		
		if (root == NULL) {
			return {0, 0};
		}
		
		auto left = solve(root->left);
		auto right = solve(root->right);
		
		int include = root->data + left.second + right.second;
		int exclude = max(left.first, left.second) + max(right.first, right.second);
		
		return {include, exclude};
		
	}
	
	public:
	int getMaxSum(Node *root) {
		
		auto ans = solve(root);
		return max(ans.first, ans.second);
		
	}
};
