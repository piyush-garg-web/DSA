class Solution {
	private:
	bool solve (int V, int cost, vector<vector<int>> & edges, int k, unordered_map<int, vector<pair<int, int>>>& adj, vector<bool>& visited) {
		
		if (cost >= k) {
			return true;
		}
		
		visited[V] = true;
		
		for (auto edge:adj[V]) {
			
			int neighbour = edge.first;
			int weight = edge.second;
			
			if (!visited[neighbour]) {
				
				if (solve(neighbour, cost + weight, edges, k, adj, visited)) {
					return true;
				}
			}
		}
		
		visited[V] = false;
		
		return false;
		
	}
	
	public:
	bool pathMoreThanK(int V, vector<vector<int>> & edges, int k) {
		
		unordered_map<int, vector<pair<int, int>> > adj;
		
		for (auto it:edges) {
			
			int u = it[0];
			int v = it[1];
			int w = it[2];
			
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
			
		}
		
		vector<bool> visited (V, false);
		
		return solve (0, 0, edges, k, adj, visited);
		
	}
};
