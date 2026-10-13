class Solution {
	private:
	vector<int> topoSort (unordered_map<int, vector<int>> & adj, vector<int>& indegree, set<char>& unique) {
		
		queue<int> q;
		
		for (auto ch : unique) {
			
			int node = ch - 'a';
			
			if (indegree[node] == 0) {
				
				q.push(node);
			}
		}
		
		vector<int> topo;
		
		while (!q.empty()) {
			
			int node = q.front();
			q.pop();
			topo.push_back(node);
			
			for (auto nbr : adj[node]) {
				
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					
					q.push(nbr);
				}
				
			}
		}
		
		return topo;
	}
	
	public:
	string findOrder(vector<string> &words) {
		
		set<char> unique;
		
		for (auto word : words) {
			
			for (auto ch : word) {
				
				unique.insert(ch);
			}
		}
		
		unordered_map<int, vector<int>> adj;
		vector<int> indegree (26, 0);
		int n = words.size();
		
		for (int i = 0; i<n - 1; i++) {
			
			string one = words[i];
			string two = words[i + 1];
			
			bool found = false;
			int len = min(one.size(), two.size());
			
			for (int j = 0; j<len; j++) {
				
				if (one[j] != two[j]) {
					
					int u = one[j]-'a';
					int v = two[j]-'a';
					
					adj[u].push_back(v);
					indegree[v]++;
					
					found = true;
					break;
				}
			}
			
			if (!found && one.size()>two.size()) {
				
				return "";
			}
		}
		
		vector<int> topo = topoSort(adj, indegree, unique);
		
		if (topo.size() != unique.size()) {
			
			return "";
		}
		
		string ans = "";
		
		for (auto ch : topo) {
			
			ans += char(ch + 'a');
		}
		
		return ans;
		
	}
};
