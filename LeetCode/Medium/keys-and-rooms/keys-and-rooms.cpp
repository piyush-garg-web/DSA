class Solution {
private:
    void solve(vector<vector<int>>& rooms, vector<bool>& visited) {
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (int i = 0; i < rooms[front].size(); i++) {
                if (!visited[rooms[front][i]]) {
                    visited[rooms[front][i]] = true;
                    q.push(rooms[front][i]);
                }
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        solve(rooms, visited);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};