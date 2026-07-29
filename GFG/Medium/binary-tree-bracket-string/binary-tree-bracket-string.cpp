class Node {
	public:
	int data;
	Node *left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; 

class Solution {
	private:
	Node* build(string&s, int& i) {
		
		if (i >= s.size()) {
			return NULL;
		}
		
		int sign = 1;
		if (s[i] == '-') {
			sign = -1;
			i++;
		}
		
		int num = 0;
		
		while (i<s.size() && isdigit(s[i])) {
			num = num*10 + (s[i]-'0');
			i++;
		}
		
		Node* root = new Node(num*sign);
		
		if (i<s.size() && s[i] == '(') {
			
			i++;
			
			if (s[i] == ')') {
				root->left = NULL;
				i++;
			}
			
			else {
				root->left = build(s, i);
				i++;
			}
		}
		
		if (i<s.size() && s[i] == '(') {
			
			i++;
			
			if (s[i] == ')') {
				root->right = NULL;
				i++;
			}
			
			else {
				root->right = build(s, i);
				i++;
			}
		}
		
		return root;
		
	}
	
	public:
	Node *treeFromString(string &s) {
		
		int i = 0;
		return build(s, i);
		
	}
};
