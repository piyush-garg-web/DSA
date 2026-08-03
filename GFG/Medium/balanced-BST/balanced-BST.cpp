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
	void inorder(Node* root, vector<int>& store) {
		
		if (root == NULL) {
			return;
		}
		
		inorder(root->left, store);
		store.push_back(root->data);
		inorder(root->right, store);
	}
	
	Node* solve (vector<int>& store, int start, int end) {
		
		if (start>end) {
			return NULL;
		}
		
		int mid = start + (end - start)/2;
		Node* root = new Node(store[mid]);
		
		root->left = solve(store, start, mid - 1);
		root->right = solve(store, mid + 1, end);
		
		return root;
	}
	
	public:
	Node* balanceBST(Node* root) {
		
		vector<int> store;
		
		inorder(root, store);
		
		return solve (store, 0, store.size() - 1);
		
	}
};
