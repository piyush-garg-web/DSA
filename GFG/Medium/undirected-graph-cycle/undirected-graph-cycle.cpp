class Solution {
	private:
	
	bool bfs (int node, unordered_map<int, vector<int>> & adj, vector<bool>& visited) {
		
		unordered_map<int, int> parent;
		queue<int> q;
		
		q.push(node);
		parent[node] = -1;
		visited[node] = true;
		
		while (!q.empty()) {
			
			int top = q.front();
			q.pop();
			
			for (auto nbr : adj[top]) {
				
				if (!visited[nbr]) {
					
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = top;
				}
				
				else if (visited[nbr] == true && parent[top] != nbr) {
					
					return true;
				}
			}
		}
		
		return false;
	}
	
	public:
	bool isCycle(int V, vector<vector<int>> & edges) {
		
		unordered_map<int, vector<int>> adj;
		
		for (int i = 0; i<edges.size(); i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<bool> visited (V, false);
		
		for (int i = 0; i<V; i++) {
			
			if (!visited[i]) {
				
				bool ans = bfs(i, adj, visited);
				
				if (ans == true) {
					
					return true;
				}
				
			}
		}
		
		return false;
		
	}
};
