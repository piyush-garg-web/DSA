class Solution {
private:
    bool isValid(int r, int c, int& rows, int& columns) {
        if (r >= 0 && r < rows && c >= 0 && c < columns) {
            return true;
        }

        return false;
    }

public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int columns = moveTime[0].size();
        vector<vector<int>> time(rows, vector<int>(columns, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        time[0][0] = 0;
        int dir[] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int currTime = top[0];
            int currRow = top[1];
            int currCol = top[2];

            if (currRow == rows - 1 && currCol == columns - 1) {
                return currTime;
            }

            for (int i = 0; i < 4; i++) {
                int newRow = currRow + dir[i];
                int newCol = currCol + dir[i + 1];

                if (isValid(newRow, newCol, rows, columns)) {
                    int newTime = max(currTime, moveTime[newRow][newCol]) + 1;

                    if (newTime < time[newRow][newCol]) {
                        pq.push({newTime, newRow, newCol});
                        time[newRow][newCol] = newTime;
                    }
                }
            }
        }

        return -1;
    }
};