class Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
}; 

class Solution {
	private:
	bool solve (Node* root, int mini, int maxi) {
		
		if (root == NULL) {
			return false;
		}
		
		if (mini == maxi) {
			return true;
		}
		
		bool left = solve(root->left, mini, root->data - 1);
		bool right = solve(root->right, root->data + 1, maxi);
		
		return left || right;
	}
	
	public:
	bool isDeadEnd(Node *root) {
		
		return solve (root, 1, INT_MAX);
		
	}
};
