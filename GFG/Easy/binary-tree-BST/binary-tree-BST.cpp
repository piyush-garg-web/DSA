struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

class Solution {
	private:
	void inorder(Node* root, vector<int>& ans) {
		
		if (root == NULL) {
			return;
		}
		
		inorder(root->left, ans);
		ans.push_back(root->data);
		inorder(root->right, ans);
	}
	
	void replace(Node* root, vector<int>& ans, int& i) {
		
		if (root == NULL) {
			return;
		}
		
		replace(root->left, ans, i);
		root->data = ans[i];
		i++;
		replace(root->right, ans, i);
		
	}
	
	public:
	Node *binaryTreeToBST(Node *root) {
		
		vector<int> ans;
		inorder(root, ans);
		
		sort(ans.begin(), ans.end());
		int i = 0;
		replace(root, ans, i);
		
		return root;
		
	}
};
