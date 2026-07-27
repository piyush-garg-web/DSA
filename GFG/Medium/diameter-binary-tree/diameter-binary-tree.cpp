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
	int solve (Node* root, int& ans) {
		
		if (root == NULL) {
			return 0;
		}
		
		int leftHeight = solve(root->left, ans);
		int rightHeight = solve(root->right, ans);
		
		ans = max(ans, leftHeight + rightHeight);
		
		return 1 + max(leftHeight, rightHeight);
	}
	
	public:
	int diameter(Node* root) {
		
		int ans = 0;
		solve(root, ans);
		return ans;
		
	}
};
