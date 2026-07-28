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
	bool solve (Node* root, int& prevLevel, int currLevel) {
		
		if (root == NULL) {
			return true;
		}
		
		if (root->left == NULL && root->right == NULL) {
			
			if (prevLevel == -1) {
				prevLevel = currLevel;
				return true;
			}
			
			return currLevel == prevLevel;
		}
		
		bool left = solve(root->left, prevLevel, currLevel + 1);
		bool right = solve(root->right, prevLevel, currLevel + 1);
		
		return left && right;
	}
	
	public:
	bool check(Node* root) {
		
		int prevLevel = -1;
		return solve(root, prevLevel, 0);
		
	}
};
