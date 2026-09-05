class Solution {
	private:
	bool dfs (int node, int col, unordered_map<int, vector<int>> & adj, vector<int>& color) {
		
		color[node] = col;
		
		for (auto nbr : adj[node]) {
			
			if (color[nbr] == -1) {
				
				if (!dfs(nbr, !col, adj, color)) {
					
					return false;
				}
			}
			
			else if (color[nbr] == col) {
				
				return false;
			}
		}
		
		return true;
	}
	
	public:
	bool isBipartite(int V, vector<vector<int>> &edges) {
		
		unordered_map<int, vector<int>> adj;
		vector<int> color (V, -1);
		
		for (int i = 0; i<edges.size(); i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		for (int i = 0; i<V; i++) {
			
			if (color[i] == -1) {
				
				if (!dfs(i, 0, adj, color)) {
					
					return false;
				}
			}
		}
		
		return true;
		
	}
};
