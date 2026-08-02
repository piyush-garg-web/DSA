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
	void solve (Node* root, int& k, int& ans) {
		if (root == NULL || k == 0) {
			
			return;
		}
		
		solve(root->left, k, ans);
		
		k--;
		if (k == 0) {
			ans = root->data;
			return;
		}
		
		solve(root->right, k, ans);
	}
	
	public:
	int kthSmallest(Node *root, int k) {
		
		int ans = -1;
		solve(root, k, ans);
		return ans;
		
	}
};
