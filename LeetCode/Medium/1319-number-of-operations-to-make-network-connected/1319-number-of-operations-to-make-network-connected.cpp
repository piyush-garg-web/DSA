class Solution {
private:
    void bfs(int i, unordered_map<int, list<int>>& adjList,
             vector<int>& visited) {
        queue<int> q;
        q.push(i);
        visited[i] = 1;

        while (!q.empty()) {
            int top = q.front();
            q.pop();
            for (auto nbr : adjList[top]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int>> adjList;
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        int cables = connections.size();
        int count = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                bfs(i, adjList, visited);
            }
        }

     if (cables<n-1) {
        return -1;
     }

     else {
        return count-1;
     }
     
    }
};