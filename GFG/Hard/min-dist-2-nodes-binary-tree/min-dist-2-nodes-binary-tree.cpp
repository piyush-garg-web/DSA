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
	Node* findLCA (Node* root, int a, int b) {
		
		if (root == NULL) {
			return NULL;
		}
		
		if (root->data == a || root->data == b) {
			return root;
		}
		
		Node* left = findLCA(root->left, a, b);
		Node* right = findLCA(root->right, a, b);
		
		if (left == NULL && right == NULL) {
			return NULL;
		}
		
		else if (left != NULL && right == NULL) {
			return left;
		}
		
		else if (left == NULL && right != NULL) {
			return right;
		}
		
		else {
			return root;
		}
	}
	
	int distance(Node* root, int val) {
		
		if (root == NULL) {
			return - 1;
		}
		
		if (root->data == val) {
			return 0;
		}
		
		int left = distance(root->left, val);
		if (left != -1) {
			return left + 1;
		}
		
		int right = distance(root->right, val);
		if (right!=-1) {
			return right + 1;
		}
		
		return - 1;
	}
	public:
	int findDist(Node* root, int a, int b) {
		
		Node* lca = findLCA(root, a, b);
		
		int d1 = distance(lca, a);
		int d2 = distance(lca, b);
		
		return d1 + d2;
		
	}
};
