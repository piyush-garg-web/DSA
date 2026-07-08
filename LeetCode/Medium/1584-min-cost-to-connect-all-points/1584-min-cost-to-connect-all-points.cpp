class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int minCost = 0;
        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, 0);
        minDist[0] = 0;

        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            int u = -1;

            for (int j = 0; j < n; j++) {
                if (visited[j] != 1 && minDist[j] < mini) {
                    u = j;
                    mini = minDist[j];
                }
            }

            visited[u] = 1;
            minCost += minDist[u];

            for (int k = 0; k < n; k++) {
                int distance = abs(points[u][0] - points[k][0]) +
                               abs(points[u][1] - points[k][1]);

                if (!visited[k] && distance < minDist[k]) {
                    minDist[k] = distance;
                }
            }
        }

        return minCost;
    }
};