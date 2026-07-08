class Solution {
private:
    void solve(vector<vector<int>>& rooms, vector<bool>& visited) {
        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (int i = 0; i < rooms[front].size(); i++) {
                if (visited[rooms[front][i]] != 1) {
                    visited[rooms[front][i]] = 1;
                    q.push(rooms[front][i]);
                }
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n);
        solve(rooms, visited);

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                return false;
            }
        }

        return true;
    }
};