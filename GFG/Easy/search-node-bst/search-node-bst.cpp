class Node {
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};

class Solution {
	public:
	bool search(Node* root, int key) {
		
		while (root != NULL) {
			
			if (root->data == key) {
				return true;
			}
			
			else if (root->data<key) {
				root = root->right;
			}
			
			else {
				root = root->left;
			}
		}
		
		return false;
		
	}
};
