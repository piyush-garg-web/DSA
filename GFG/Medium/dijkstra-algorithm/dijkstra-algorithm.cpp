class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		
		vector<int> distance (V, INT_MAX);
		unordered_map<int, vector<pair<int, int>> > adj;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		
		for (int i = 0; i<edges.size(); i++) {
			
			int u = edges[i][0];
			int v = edges[i][1];
			int w = edges[i][2];
			
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
			
		}
		
		distance[src] = 0;
		pq.push({0, src});
		
		while (!pq.empty()) {
			
			auto front = pq.top();
			pq.pop();
			
			int dist = front.first;
			int node = front.second;
			
			if (dist>distance[node]) {
				
				continue;
			}
			
			for (auto nbr : adj[node]) {
				
				int v = nbr.first;
				int w = nbr.second;
				
				if (dist + w <distance[v]) {
					
					distance[v] = dist + w;
					pq.push({dist + w, v});
				}
			}
		}
		
		return distance;
		
	}
};
