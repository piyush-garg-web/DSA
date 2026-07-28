struct Node
{
	int data;
	Node* left, * right;
}; 

class Solution {
	public:
	vector<int> diagonal(Node *root) {
		
		vector<int> ans;
		queue<Node*> q;
		
		q.push(root);
		
		while (!q.empty()) {
			
			Node* it = q.front();
			q.pop();
			
			while (it != NULL) {
				
				ans.push_back(it->data);
				
				if (it->left) {
					q.push(it->left);
				}
				
				it = it->right;
			}
		}
		
		return ans;
		
	}
};
