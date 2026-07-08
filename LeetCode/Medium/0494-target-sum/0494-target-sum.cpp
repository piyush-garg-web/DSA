class Solution {
private:
    int solve(int n, vector<int>& nums, int s, int target) {

        vector<vector<int>> dp(n + 1, vector<int>(2 * s + 1, 0));

        dp[0][s] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = -s; j <= s; j++) {
                if (dp[i - 1][j + s] != 0) {

                    if (j + nums[i - 1] + s >= 0 &&
                        j + nums[i - 1] + s <= 2 * s) {
                        dp[i][j + nums[i - 1] + s] += dp[i - 1][j + s];
                    }

                    if (j - nums[i - 1] + s >= 0 &&
                        j - nums[i - 1] + s <= 2 * s) {
                        dp[i][j - nums[i - 1] + s] += dp[i - 1][j + s];
                    }
                }
            }
        }

        if (target > s || target < -s) {
            return 0;
        }
        return dp[n][target + s];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
        }
        return solve(n, nums, s, target);
    }
};