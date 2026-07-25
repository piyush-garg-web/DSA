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
	vector<int> bottomView(Node *root) {
		
		vector<int> ans;
		unordered_map<int, int> mp;
		queue<pair<Node*, int>> q;
		int mini = 0;
		int maxi = 0;
		
		q.push({root, 0});
		
		while (!q.empty()) {
			
			auto it = q.front();
			q.pop();
			
			mp[it.second] = it.first->data;
			
			mini = min(mini, it.second);
			maxi = max(maxi, it.second);
			
			if (it.first->left) {
				q.push({it.first->left, it.second - 1});
			}
			
			if (it.first->right) {
				q.push({it.first->right, it.second + 1});
			}
		}
		
		for (int i = mini; i <= maxi; i++) {
			ans.push_back(mp[i]);
		}
		
		return ans;
		
	}
};
