class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        unordered_map<int, unordered_set<int>> adj;

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            degree[u]++;
            degree[v]++;
            adj[u].insert(v);
            adj[v].insert(u);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];

                if (adj[i].count(j)) {
                    rank--;
                }

                ans = max(ans, rank);
            }
        }

        return ans;
    }
};