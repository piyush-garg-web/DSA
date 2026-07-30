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
	string solve (Node* root, unordered_map<string, int>& mp, bool& ans) {
		
		if (root == NULL)
			{
			return "N";
		}
		
		string left = solve(root->left, mp, ans);
		string right = solve(root->right, mp, ans);
		
		string curr = to_string(root->data) + "," + left + "," + right;
		
		if (root->left || root->right) {
			
			mp[curr]++;
			
			if (mp[curr]>1) {
				ans = true;
			}
		}
		
		return curr;
	}
	
	public:
	bool dupSub(Node* root) {
		
		unordered_map<string, int> mp;
		bool ans = false;
		
		solve(root, mp, ans);
		return ans;
	}
};
