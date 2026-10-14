class Solution {
	private:
	int solve (int n, vector<int>& coins, int index, vector<vector<int>> & dp) {
		
		if (n == 0) {
			
			return 1;
		}
		
		if (n<0 || index >= coins.size()) {
			
			return 0;
		}
		
		if (dp[n][index] != -1) {
			
			return dp[n][index];
		}
		
		int take = solve(n - coins[index], coins, index, dp);
		int notTake = solve(n, coins, index + 1, dp);
		
		return dp[n][index] = take + notTake;
	}
	
	public:
	int countWays(int n) {
		
		vector<int> coins = {3, 5, 10};
		vector<vector<int>> dp (n + 1, vector<int> (3, -1));
		return solve(n, coins, 0, dp);
		
	}
};
