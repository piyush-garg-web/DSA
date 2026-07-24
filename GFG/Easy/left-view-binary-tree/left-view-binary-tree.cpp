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
	public:
	vector<int> leftView(Node *root) {
		
		vector<int> ans;
		
		if (root == NULL) {
			return ans;
		}
		
		queue<Node*> q;
		q.push(root);
		
		while (!q.empty()) {
			
			int size = q.size();
			
			for (int i = 0; i<size; i++) {
				
				auto it = q.front();
				q.pop();
				
				if (i == 0) {
					ans.push_back(it->data);
				}
				
				if (it->left) {
					q.push(it->left);
				}
				
				if (it->right) {
					q.push(it->right);
				}
			}
			
		}
		
		return ans;
		
	}
};
