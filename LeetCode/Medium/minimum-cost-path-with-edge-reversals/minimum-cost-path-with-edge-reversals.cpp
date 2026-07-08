class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<pair<int, int>>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, 2 * w));
        }

        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, 0));
        distance[0] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (top.first > distance[top.second]) {
                continue;
            }

            if (top.second == n - 1) {
                return top.first;
            }

            for (auto nbr : adj[top.second]) {
                if (top.first + nbr.second < distance[nbr.first]) {
                    pq.push(make_pair(top.first + nbr.second, nbr.first));
                    distance[nbr.first] = top.first + nbr.second;
                }
            }
        }

        return -1;
    }
};