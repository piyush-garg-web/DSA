class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	// Constructor
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

class Solution {
	public:
	vector<int> levelOrder(Node *root) {
		
		vector<int> ans;
		queue<Node*> q;
		
		q.push(root);
		
		while (!q.empty()) {
			
			auto it = q.front();
			q.pop();
			ans.push_back(it->data);
			
			if (it->left != NULL) {
				q.push(it->left);
			}
			
			if (it->right != NULL) {
				q.push(it->right);
			}
		}
		
		return ans;
		
	}
};
