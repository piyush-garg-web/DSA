class Solution {
private:
    void dfs(int node, int& ans, vector<int>& vis, vector<int>& depth,
             vector<int>& edges) {
        vis[node] = 1;
        int next = edges[node];
        if (next != -1) {
            if (vis[next] == 0) {
                depth[next] = depth[node] + 1;
                dfs(next, ans, vis, depth, edges);

            }

            else if (vis[next] == 1) {
                ans = max(ans, depth[node] - depth[next] + 1);
            }
        }
        vis[node] = 2;
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> depth(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, ans, vis, depth, edges);
            }
        }
        return ans;
    }
};