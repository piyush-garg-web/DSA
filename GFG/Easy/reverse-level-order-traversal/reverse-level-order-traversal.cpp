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
	vector<int> reverseLevelOrder(Node *root) {
		
		vector<int> ans;
		queue<Node*> q;
		
		q.push(root);
		
		while (!q.empty()) {
			
			auto it = q.front();
			q.pop();
			ans.push_back(it->data);
			
			if (it->right != NULL) {
				q.push(it->right);
			}
			
			if (it->left != NULL) {
				q.push(it->left);
			}
		}
		
		reverse(ans.begin(), ans.end());
		
		return ans;
	}
};
