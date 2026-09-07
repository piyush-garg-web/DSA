class Solution {
	private:
	static bool cmp (vector<int>& a, vector<int>& b) {
		
		return a[2]<b[2];
	}
	
	int findParent (vector<int>& parent, int node) {
		
		if (parent[node] == node) {
			
			return node;
		}
		
		return parent[node] = findParent(parent, parent[node]);
	}
	
	void findUnion (int node1, int node2, vector<int>& rank, vector<int>& parent) {
		
		int u = findParent(parent, node1);
		int v = findParent(parent, node2);
		
		if (rank[u]<rank[v]) {
			
			parent[u] = v;
			
		}
		
		else if (rank[v]<rank[u]) {
			
			parent[v] = u;
		}
		
		else {
			
			parent[u] = v;
			rank[v]++;
		}
	}
	
	public:
	int kruskalsMST(int V, vector<vector<int>> &edges) {
		
		vector<int> parent (V);
		vector<int> rank (V, 0);
		
		for (int i = 0; i<V; i++) {
			
			parent[i] = i;
		}
		
		sort(edges.begin(), edges.end(), cmp);
		
		int ans = 0;
		
		for (int i = 0; i<edges.size(); i++) {
			
			int u = findParent(parent, edges[i][0]);
			int v = findParent(parent, edges[i][1]);
			
			if (u != v) {
				
				ans += edges[i][2];
				findUnion(u, v, rank, parent);
			}
		}
		
		return ans;
	}
};
