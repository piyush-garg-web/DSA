class Solution {
	private:
	class Node {
		public:
		int freq;
		int index;
		Node* left;
		Node* right;
		
		Node (int f, int i) {
			freq = f;
			index = i;
			left = NULL;
			right = NULL;
		}
	};
	
	class Compare {
		public:
		bool operator()(Node* a, Node* b) {
			
			if (a->freq == b->freq) {
				return a->index>b->index;
			}
			
			return a->freq>b->freq;
			
		}
		
	};
	
	void preorder(Node* root, string temp, vector<string>& ans) {
		if (root == NULL) {
			return;
		}
		
		if (root->left == NULL && root->right == NULL) {
			ans.push_back(temp);
			return;
		}
		
		preorder(root->left, temp + "0", ans);
		preorder(root->right, temp + "1", ans);
	}
	
	public:
	vector<string> huffmanCodes(string &s, vector<int> f) {
		
		if (s.size() == 1) {
			
			return {"0"};
		}
		
		priority_queue<Node*, vector<Node*>, Compare> pq;
		
		for (int i = 0; i<s.size(); i++) {
			
			pq.push(new Node(f[i], i));
		}
		
		while (pq.size()>1) {
			auto left = pq.top();
			pq.pop();
			
			auto right = pq.top();
			pq.pop();
			
			Node* parent = new Node(left->freq + right->freq, min(left->index, right->index));
			
			parent->left = left;
			parent->right = right;
			
			pq.push(parent);
		}
		
		Node* root = pq.top();
		
		vector<string> ans;
		string temp = "";
		
		preorder(root, temp, ans);
		
		return ans;
		
	}
};
