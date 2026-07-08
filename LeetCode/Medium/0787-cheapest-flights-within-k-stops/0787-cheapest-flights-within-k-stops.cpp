class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;

            for (auto nbr : flights) {
                int u = nbr[0];
                int v = nbr[1];
                int w = nbr[2];

                if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }

            dist = temp;
        }

        if (dist[dst] == INT_MAX) {
            return -1;
        }

        return dist[dst];
    }
};