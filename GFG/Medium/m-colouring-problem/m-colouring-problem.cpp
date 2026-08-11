class Solution {
	private:
	bool isSafe (int node, unordered_map<int, vector<int>> & adj, vector<int>& coloured, int color) {
		
		for (auto it :adj[node]) {
			
			if (coloured[it] == color) {
				return false;
			}
		}
		
		return true;
	}
	
	bool solve (int node, int v, vector<vector<int>> &edges, unordered_map<int, vector<int>> & adj, int m, vector<int>& coloured) {
		
		if (node == v) {
			return true;
		}
		
		for (int color = 1; color <= m; color++) {
			
			if (isSafe(node, adj, coloured, color)) {
				
				coloured[node] = color;
				
				if (solve(node + 1, v, edges, adj, m, coloured)) {
					return true;
				}
				
				coloured[node] = 0;
			}
		}
		
		return false;
	}
	
	public:
	bool graphColoring(int v, vector<vector<int>> &edges, int m) {
		
		unordered_map<int, vector<int>> adj;
		
		for (auto it : edges) {
			
			int u = it[0];
			int v = it[1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<int> coloured (v, 0);
		
		return solve (0, v, edges, adj, m, coloured);
		
	}
};
