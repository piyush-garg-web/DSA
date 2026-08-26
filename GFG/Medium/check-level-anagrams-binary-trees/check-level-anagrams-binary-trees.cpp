class Node {
	public:
	int data;
	Node *left, *right;
	Node(int x) {
		data = x;
		left = right = nullptr;
	}
}; 

class Solution {
	public:
	bool areAnagrams(Node* root1, Node* root2) {
		
		queue<Node*> q1;
		queue<Node*> q2;
		
		q1.push(root1);
		q2.push(root2);
		
		while (!q1.empty() && !q2.empty()) {
			
			int n1 = q1.size();
			int n2 = q2.size();
			
			if (n1 != n2) {
				
				return false;
			}
			
			unordered_map<int, int> mp;
			
			for (int i = 0; i<n1; i++) {
				
				Node* front = q1.front();
				q1.pop();
				
				mp[front->data]++;
				
				if (front->left) {
					
					q1.push(front->left);
				}
				
				if (front->right) {
					
					q1.push(front->right);
				}
			}
			
			for (int i = 0; i<n2; i++) {
				
				Node* front = q2.front();
				q2.pop();
				
				mp[front->data]--;
				
				if (front->left) {
					
					q2.push(front->left);
					
				}
				
				if (front->right) {
					
					q2.push(front->right);
				}
			}
			
			for (auto it:mp) {
				
				if (it.second != 0) {
					
					return false;
				}
			}
		}
		
		return q1.empty() && q2.empty();
		
	}
};
