class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> ans(n);
        unordered_map<int, list<int>> adj;
        vector<int> indegree(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            for (int nbr : adj[top]) {
                ans[nbr].insert(top);

                for (int it : ans[top]) {
                    ans[nbr].insert(it);
                }

                indegree[nbr]--;

                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        
        vector<vector<int>> result(n);
        
        for (int i=0;i<n;i++) {
            result[i]=vector<int>(ans[i].begin(),ans[i].end());
        }

        return result;
    }
};