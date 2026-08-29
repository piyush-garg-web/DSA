class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

class Solution {
	private:
	int totalNodes(Node* tree) {
		
		if (tree == NULL) {
			
			return 0;
		}
		
		return 1 + totalNodes(tree->left) + totalNodes(tree->right);
	}
	
	bool isCBT (Node* tree, int index, int totalNodes) {
		
		if (tree == NULL) {
			
			return true;
		}
		
		if (index >= totalNodes) {
			
			return false;
		}
		
		bool left = isCBT(tree->left, 2*index + 1, totalNodes);
		bool right = isCBT(tree->right, 2*index + 2, totalNodes);
		
		return left && right;
	}
	
	bool maxHeap (Node* tree) {
		
		if (tree == NULL) {
			
			return true;
		}
		
		if (tree->left == NULL && tree->right == NULL) {
			
			return true;
		}
		
		if (tree->right == NULL) {
			
			return (tree->data> tree->left->data);
		}
		
		bool left = maxHeap(tree->left);
		bool right = maxHeap(tree->right);
		
		return (left && right && tree->data > tree->left->data && tree->data > tree->right->data);
	}
	
	public:
	bool isHeap(Node* tree) {
		
		int count = totalNodes(tree);
		int index = 0;
		
		return (isCBT(tree, index, count) && maxHeap(tree));
		
	}
};
