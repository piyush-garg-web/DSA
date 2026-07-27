class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
}; 

class Solution {
	private:
	pair <int, int> solve (Node* root) {
		
		if (root == NULL) {
			return {-1, 0};
		}
		
		auto left = solve(root->left);
		auto right = solve(root->right);
		
		if (left.first> right.first) {
			
			return {left.first + 1, left.second + root->data};
		}
		
		if (right.first>left.first) {
			
			return {right.first + 1, right.second + root->data};
		}
		
		return {left.first + 1, max(left.second, right.second) + root->data};
	}
	
	public:
	int sumOfLongRootToLeafPath(Node *root) {
		
		return solve(root).second;
		
	}
};
