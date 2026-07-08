class Solution {
private:
    bool isValid(int r, int c, int& rows, int& columns) {
        if (r >= 0 && r < rows && c >= 0 && c < columns) {
            return 1;
        }

        return 0;
    }

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int dist[] = {-1, 0, 1, 0, -1};
        int rows = moveTime.size();
        int columns = moveTime[0].size();
        int cost = 1;
    vector<vector<vector<int>>> time(rows,
    vector<vector<int>>(columns, vector<int>(2, INT_MAX)));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        pq.push({0, 0, 0, 1});
        time[0][0][0] = 0;
        int newTime;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int currTime = top[0];
            int currRow = top[1];
            int currCol = top[2];
            int currCost = top[3];
            if (currRow == rows - 1 && currCol == columns - 1) {
                return currTime;
            }
            for (int i = 0; i < 4; i++) {
                int newRow = currRow + dist[i];
                int newCol = currCol + dist[i + 1];
                int newCost = (currCost == 1) ? 2 : 1;
                if (isValid(newRow, newCol, rows, columns)) {
                    newTime =
                        max(currTime, moveTime[newRow][newCol]) + currCost;
                    if (newTime < time[newRow][newCol][currCost-1]) {
                        pq.push({newTime, newRow, newCol, newCost});
                        time[newRow][newCol][currCost-1] = newTime;
                    }
                }
            }
        }

        return -1;
    }
};