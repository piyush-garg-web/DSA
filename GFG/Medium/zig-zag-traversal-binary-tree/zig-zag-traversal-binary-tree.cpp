class Node {
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

class Solution {
	public:
	vector<int> zigZagTraversal(Node* root) {
		
		vector<int> ans;
		queue<Node*> q;
		
		bool leftToRight = 1;
		q.push(root);
		
		while (!q.empty()) {
			
			int size = q.size();
			vector<int> level (size);
			
			for (int i = 0; i<size; i++) {
				
				auto it = q.front();
				q.pop();
				int index;
				
				if (leftToRight) {
					index = i;
				}
				
				else {
					index = size - i-1;
				}
				
				level[index] = it->data;
				
				if (it->left) {
					q.push(it->left);
				}
				
				if (it->right) {
					q.push(it->right);
				}
				
			}
			
			for (int x: level) {
				ans.push_back(x);
			}
			
			leftToRight = !leftToRight;
		}
		
		return ans;
	}
	
};
