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
	vector<int> rightView(Node *root) {
		
		vector<int> ans;
		queue<Node*> q;
		
		q.push(root);
		
		while (!q.empty()) {
			
			int size = q.size();
			
			for (int i = 0; i<size; i++) {
				
				auto it = q.front();
				q.pop();
				
				if (i == size - 1) {
					
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
