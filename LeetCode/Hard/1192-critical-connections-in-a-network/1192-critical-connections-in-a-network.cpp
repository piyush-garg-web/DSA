class Solution {
private:
    void dfs(int node, int parent, unordered_map<int, list<int>>& adj,
             vector<int>& disc, vector<int>& low, int timer,
             vector<bool>& visited, vector<vector<int>>& ans) {
        visited[node] = 1;
        disc[node] = low[node] = timer++;
        for (auto nbr : adj[node]) {
            if (nbr == parent) {
                continue;
            }

            if (!visited[nbr]) {
                dfs(nbr, node, adj, disc, low, timer, visited, ans);
                low[node] = min(low[node], low[nbr]);
                if (low[nbr] > disc[node]) {
                    vector<int> res;
                    res.push_back(node);
                    res.push_back(nbr);
                    ans.push_back(res);
                }
            } else {
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<vector<int>> ans;
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        int parent = -1;
        int timer = 0;
        vector<bool> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, disc, low, timer, visited, ans);
            }
        }

        return ans;
    }
};