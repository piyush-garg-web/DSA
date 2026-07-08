class Solution {
private:
    int solve(int n, vector<int>& coins, int amount) {
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(n, coins, amount);
    }
};