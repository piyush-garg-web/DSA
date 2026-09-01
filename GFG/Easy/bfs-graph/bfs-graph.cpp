class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		
		vector<int> ans;
		queue<int> q;
		int n = adj.size();
		vector<bool> visited (n, false);
		
		q.push(0);
		visited[0] = true;  
		
		while (!q.empty()) {
			
			int top = q.front();
			q.pop();
			
			ans.push_back(top);
			
			for (int it : adj[top]) {
				
				if (!visited[it]) {
					
					visited[it] = true;
					q.push(it);
				}
			}
		}
		
		return ans;
		
	}
};
