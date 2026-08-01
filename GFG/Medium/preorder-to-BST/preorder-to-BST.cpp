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
	Node* solve (vector<int>& pre, int& i, int mini, int maxi) {
		
		if (i >= pre.size()) {
			return NULL;
		}
		
		if (pre[i]< mini || pre[i]>maxi) {
			return NULL;
		}
		
		Node* root = new Node(pre[i]);
		i++;
		
		root->left = solve(pre, i, mini, root->data);
		root->right = solve(pre, i, root->data, maxi);
		
		return root;
	}
	public:
	Node* preToBST(vector<int>& pre) {
		
		int i = 0;
		return solve(pre, i, INT_MIN, INT_MAX);
		
	}
};
