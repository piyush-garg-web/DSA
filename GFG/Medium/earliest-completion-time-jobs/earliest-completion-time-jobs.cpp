class Solution {
	public:
	vector<int> minTime(int V, vector<vector<int>> &edges) {
		
		unordered_map<int, vector<int>> adj;
		vector<int> indegree (V + 1, 0);
		vector<int> time (V + 1, 0);
		queue<int> q;
		
		for (int i = 0; i<edges.size(); i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			
			adj[u].push_back(v);
			indegree[v]++;
		}
		
		for (int i = 1; i <= V; i++) {
			
			if (indegree[i] == 0) {
				
				time[i] = 1;
				q.push(i);
			}
		}
		
		while (!q.empty()) {
			
			int node = q.front();
			q.pop();
			
			for (auto nbr : adj[node]) {
				
				indegree[nbr]--;
				
				if (indegree[nbr] == 0) {
					
					time[nbr] = time[node]+1;
					q.push(nbr);
					
				}
			}
		}
		
		vector<int> ans;
		
		for (int i = 1; i <= V; i++) {
			
			ans.push_back(time[i]);
		}
		
		return ans;
		
	}
};
