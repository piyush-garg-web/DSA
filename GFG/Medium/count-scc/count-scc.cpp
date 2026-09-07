class Solution {
	private:
	void dfs (int node, stack<int>& st, vector<int>& visited, unordered_map<int, vector<int>> & adj) {
		
		visited[node] = 1;
		
		for (auto nbr : adj[node]) {
			
			if (!visited[nbr]) {
				
				dfs(nbr, st, visited, adj);
			}
		}
		
		st.push(node);
	}
	
	void revDFS (int node, unordered_map<int, vector<int>> & transpose, vector<int>& visited) {
		
		visited[node] = 1;
		
		for (auto nbr : transpose[node]) {
			
			if (!visited[nbr]) {
				
				revDFS(nbr, transpose, visited);
			}
		}
	}
	
	public:
	int countSCC(int V, vector<vector<int>> &edges) {
		
		unordered_map<int, vector<int>> adj;
		
		for (int i = 0; i<edges.size(); i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			
			adj[u].push_back(v);
		}
		
		stack<int> st;
		vector<int> visited (V, 0);
		
		for (int i = 0; i < V; i++) {
			
			if (!visited[i]) {
				dfs(i, st, visited, adj);
			}
		}
		
		unordered_map<int, vector<int>> transpose;
		
		for (int i = 0; i<V; i++) {
			
			visited[i] = 0;
			for (auto nbr : adj[i]) {
				
				transpose[nbr].push_back(i);
			}
		}
		
		int ans = 0;
		
		while (!st.empty()) {
			
			int top = st.top();
			st.pop();
			
			if (!visited[top]) {
				
				ans++;
				revDFS(top, transpose, visited);
			}
		}
		
		return ans;
		
	}
};
