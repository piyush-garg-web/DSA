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
	private:
	string solve(Node* root, vector<Node*>& ans, unordered_map<string, int>& mp) {
		if (root == NULL) {
			return "N";
		}
		
		string left = solve(root->left, ans, mp);
		string right = solve(root->right, ans, mp);
		
		string curr = to_string(root->data) + "," + left + "," + right;
		mp[curr]++;
		
		if (mp[curr] == 2) {
			ans.push_back(root);
		}
		
		return curr;
		
	}
	
	public:
	vector<Node*> printAllDups(Node* root) {
		
		vector<Node*> ans;
		unordered_map<string, int> mp;
		
		solve(root, ans, mp);
		return ans;
		
	}
};
