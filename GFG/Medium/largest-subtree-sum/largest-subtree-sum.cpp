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
	int solve (Node* root, int& ans) {
		if (root == NULL) {
			return 0;
		}
		
		int leftSum = solve(root->left, ans);
		int rightSum = solve(root->right, ans);
		
		int currentSum = leftSum + rightSum + root->data;
		ans = max(ans, currentSum);
		
		return currentSum;
	}
	
	public:
	int maxSubtreeSum(Node* root) {
		
		int ans = INT_MIN;
		solve(root, ans);
		return ans;
		
	}
};
