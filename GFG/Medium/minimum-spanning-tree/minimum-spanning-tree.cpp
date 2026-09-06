class Solution {
	public:
	int spanningTree(int V, vector<vector<int>> & edges) {
		
		unordered_map<int, vector<pair<int, int>> > adj;
		vector<int> visited (V, 0);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		
		for (int i = 0; i<edges.size(); i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		
		int ans = 0;
		pq.push({0, 0});
		
		while (!pq.empty()) {
			
			auto top = pq.top();
			pq.pop();
			
			if (visited[top.second]) {
				
				continue;
			}
			
			ans += top.first;
			visited[top.second] = true;
			
			for (auto nbr : adj[top.second]) {
				
				if (!visited[nbr.first]) {
					
					pq.push({nbr.second, nbr.first});
				}
			}
		}
		
		return ans;
	}
};
