class Node {
	public:
	int data;
	Node *left;
	Node *right;
	Node(int val)
	{
		data = val;
		left = NULL;
		right = NULL;
	}
};

class Solution {
	private:
	void inorder(Node* root, Node*& prev, Node*& head) {
		
		if (root == NULL) {
			return;
		}
		
		inorder(root->left, prev, head);
		
		if (prev == NULL) {
			
			head = root;
		}
		
		else {
			
			prev->right = root;
		}
		
		root->left = NULL;
		prev = root;
		
		inorder(root->right, prev, head);
	}
	
	public:
	Node *flattenBST(Node *root) {
		
		Node* prev = NULL;
		Node* head = NULL;
		
		inorder(root, prev, head);
		
		return head;
		
	}
};
