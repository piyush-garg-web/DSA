class Solution {
private:
    void bfs(int i, vector<bool>& visited, vector<vector<int>>& isConnected, int n) {
        queue<int> q;
        q.push(i);
        visited[i] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (isConnected[node][v] == 1 && visited[v] != 1) {
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] != 1) {
                count++;
                bfs(i, visited, isConnected, n);
            }
        }

        return count;
    }
};