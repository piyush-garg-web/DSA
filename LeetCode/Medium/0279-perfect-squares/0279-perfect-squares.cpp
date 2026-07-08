class Solution {
private:
    int solve(int n) {

        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int ans = INT_MAX;
            for (int j = 1; j * j <= n; j++) {
                if (i >= j * j) {
                    ans = min(ans, 1 + dp[i - j * j]);
                }
            }
            dp[i]=ans;
        }

        return dp[n];
    }

public:
    int numSquares(int n) { return solve(n); }
};