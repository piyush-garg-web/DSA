class Solution {
private:
    void bfs(int i, vector<bool>& visited, vector<vector<int>>& isConnected, int n) {
        queue<int> q;
        q.push(i);
        visited[i] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (isConnected[node][v] == 1 && !visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(i, visited, isConnected, n);
            }
        }

        return count;
    }
};