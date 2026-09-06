class Solution {
	public:
	bool isNegativeWeightCycle(int V, vector<vector<int>> & edges) {
		
		vector<int> dist (V, INT_MAX);
		unordered_map<int, vector<pair<int, int>> > adj;
		
		dist[0] = 0;
		
		for (int i = 0; i<V - 1; i++) {
			
			for (int j = 0; j<edges.size(); j++) {
				
				int u = edges[j][0];
				int v = edges[j][1];
				int w = edges[j][2];
				
				if (dist[u] != INT_MAX && dist[u]+w<dist[v]) {
					
					dist[v] = dist[u]+w;
				}
			}
		}
		
		bool flag = 0;
		
		for (int j = 0; j<edges.size(); j++) {
			
			int u = edges[j][0];
			int v = edges[j][1];
			int w = edges[j][2];
			
			if (dist[u] != INT_MAX && dist[u]+w<dist[v]) {
				
				dist[v] = dist[u]+w;
				flag = 1;
			}
		}
		
		if (flag == 1) {
			
			return true;
		}
		
		return false;
		
	}
};
