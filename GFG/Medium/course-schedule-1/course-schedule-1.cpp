class Solution {
	public:
	bool canFinish(int n, vector<vector<int>> & pre) {
		
		unordered_map<int, vector<int>> adj;
		queue<int> q;
		vector<int> indegree (n, 0);
		
		for (int i = 0; i<pre.size(); i++) {
			
			int u = pre[i][0];
			int v = pre[i][1];
			
			adj[v].push_back(u);
			indegree[u]++;
		}
		
		for (int i = 0; i<n; i++) {
			
			if (indegree[i] == 0) {
				
				q.push(i);
			}
		}
		
		int count = 0;
		
		while (!q.empty()) {
			
			int node = q.front();
			q.pop();
			
			count++;
			
			for (auto nbr : adj[node]) {
				
				indegree[nbr]--;
				
				if (indegree[nbr] == 0) {
					
					q.push(nbr);
				}
			}
		}
		
		if (count == n) {
			
			return true;
		}
		
		return false;
	}
};
