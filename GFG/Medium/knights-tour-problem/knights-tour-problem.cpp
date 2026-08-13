class Solution {
private:

    bool isSafe(int x, int y, int n, vector<vector<int>>& ans) {

        if (x >= 0 && x < n &&
            y >= 0 && y < n &&
            ans[x][y] == -1) {

            return true;
        }

        return false;
    }

    bool solve(int x, int y, int count, int n,
               vector<vector<int>>& ans) {

        int xd[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int yd[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        if (count == n * n) {
            return true;
        }

        for (int i = 0; i < 8; i++) {

            int newX = x + xd[i];
            int newY = y + yd[i];

            if (isSafe(newX, newY, n, ans)) {

                ans[newX][newY] = count;

                if (solve(newX, newY, count + 1, n, ans)) {
                    return true;
                }

    
                ans[newX][newY] = -1;
            }
        }

        return false;
    }

public:

    vector<vector<int>> knightTour(int n) {

        vector<vector<int>> ans(n, vector<int>(n, -1));

        ans[0][0] = 0;

        if (solve(0, 0, 1, n, ans)) {
            return ans;
        }

        return {};
    }
};