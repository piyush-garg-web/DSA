class Node {
	public:
	int data;
	Node* left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; 

class Solution {
	private:
	void leftTraversal (Node* root, vector<int>& ans) {
		
		Node* curr = root->left;
		
		while (curr) {
			
			if (curr->left || curr->right) {
				ans.push_back(curr->data);
			}
			
			if (curr->left) {
				curr = curr->left;
			}
			
			else {
				curr = curr->right;
			}
			
		}
	}
	
	void leafTraversal (Node* root, vector<int>& ans) {
		
		if (root == NULL) {
			return;
		}
		
		if (root->left == NULL && root->right == NULL) {
			ans.push_back(root->data);
			return;
		}
		
		leafTraversal(root->left, ans);
		leafTraversal(root->right, ans);
	}
	
	void rightTraversal (Node* root, vector<int>& ans) {
		
		vector<int> temp;
		
		Node* curr = root->right;
		
		while (curr) {
			
			if (curr->left || curr->right) {
				temp.push_back(curr->data);
			}
			
			if (curr->right) {
				curr = curr->right;
			}
			
			else {
				curr = curr->left;
			}
			
		}
		
		reverse(temp.begin(), temp.end());
		
		for (int x:temp) {
			ans.push_back(x);
		}
	}
	
	public:
	vector<int> boundaryTraversal(Node *root) {
		
		vector<int> ans;
		
		if (root->left == NULL && root->right == NULL) {
			
			return {root->data};
		}
		
		ans.push_back(root->data);
		
		leftTraversal(root, ans);
		leafTraversal(root, ans);
		rightTraversal(root, ans);
		
		return ans;
		
	}
};
