class Solution {
	public:
	vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
		
		unordered_map<int, vector<pair<int, int>> > adj;
		vector<int> indegree (V, 0);
		
		for (int i = 0; i<edges.size(); i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			
			adj[u].push_back({v, w});
			indegree[v]++;
		}
		
		queue<int> q;
		vector<int> topo;
		
		for (int i = 0; i<V; i++) {
			
			if (indegree[i] == 0) {
				
				q.push(i);
			}
		}
		
		while (!q.empty()) {
			
			int top = q.front();
			q.pop();
			
			topo.push_back(top);
			
			for (auto nbr : adj[top]) {
				
				indegree[nbr.first]--;
				
				if (indegree[nbr.first] == 0) {
					
					q.push(nbr.first);
				}
			}
		}
		
		vector<int> dist (V, INT_MIN);
		dist[src] = 0;
		
		for (int node : topo) {
			
			if (dist[node] == INT_MIN) {
				
				continue;
			}
			
			for (auto nbr : adj[node]) {
				
				dist[nbr.first] = max(dist[nbr.first], dist[node]+nbr.second);
			}
		}
		
		return dist;
		
	}
};
