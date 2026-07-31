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
	public:
	int minValue(Node* root) {
		
		if (root == NULL) {
			return - 1;
		}
		
		int ans = 0;
		
		while (root != NULL) {
			
			ans = root->data;
			root = root->left;
		}
		
		return ans;
		
	}
};
