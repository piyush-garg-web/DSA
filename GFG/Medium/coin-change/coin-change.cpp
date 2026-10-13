class Solution {
	int solve(vector<int>& coins, int index, int sum,
	vector<vector<int>> & dp) {
		
		if (sum == 0) {
			return 1;
		}
		
		if (index == coins.size()) {
			return 0;
		}
		
		if (dp[index][sum] != -1) {
			return dp[index][sum];
		}
		
		int take = 0;
		
		if (coins[index] <= sum) {
			take = solve(coins, index, sum - coins[index], dp);
		}
		
		int notTake = solve(coins, index + 1, sum, dp);
		
		return dp[index][sum] = take + notTake;
	}
	
	public:
	int count(vector<int>& coins, int sum) {
		
		int n = coins.size();
		vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
		return solve(coins, 0, sum, dp);
		
	}
};
