class Solution {
	bool dfs (int node, unordered_map<int, vector<int>> & adj, vector<bool>& visited, vector<bool>& dfsVisited) {
		
		visited[node] = true;
		dfsVisited[node] = true;
		
		for (auto nbr : adj[node]) {
			
			if (!visited[nbr]) {
				
				if (dfs(nbr, adj, visited, dfsVisited)) {
					
					return true;
				}
			}
			
			else if (dfsVisited[nbr]) {
				
				return true;
			}
		}
		
		dfsVisited[node] = false;
		return false;
	}
	
	public:
	bool isCyclic(int V, vector<vector<int>> &edges) {
		
		unordered_map<int, vector<int>> adj;
		vector<bool> visited (V, false);
		vector<bool> dfsVisited (V, false);
		
		for (int i = 0; i<edges.size(); i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			
			adj[u].push_back(v);
		}
		
		for (int i = 0; i<V; i++) {
			
			if (!visited[i]) {
				
				bool ans = dfs(i, adj, visited, dfsVisited);
				
				if (ans) {
					
					return true;
				}
			}
		}
		
		return false;
		
	}
};
