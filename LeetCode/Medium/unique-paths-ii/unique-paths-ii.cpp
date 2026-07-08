class Solution {
private:
    int solve(int m, int n, vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        if (obstacleGrid[0][0] == 1) {
            return 0;
        }

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }

                int down = 0;
                int right = 0;

                if (i - 1 >= 0) {
                    down = dp[i - 1][j];
                }

                if (j - 1 >= 0) {
                    right = dp[i][j - 1];
                }

                dp[i][j] = down + right;
            }
        }

        return dp[m - 1][n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return solve(m, n, obstacleGrid);
    }
};