class Solution {
	private:
	void dfs (int node, vector<vector<int>> & adj, vector<int>& ans, vector<bool>& visited) {
		
		visited[node] = true;
		ans.push_back(node);
		
		for (int it : adj[node]) {
			
			if (!visited[it]) {
				
				dfs(it, adj, ans, visited);
			}
		}
	}
	public:
	vector<int> dfs(vector<vector<int>> & adj) {
		
		vector<int> ans;
		int n = adj.size();
		vector<bool> visited (n, false);
		
		dfs(0, adj, ans, visited);
		return ans;
		
	}
};
