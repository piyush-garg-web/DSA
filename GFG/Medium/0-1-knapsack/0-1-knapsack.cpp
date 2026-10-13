class Solution {
	private:
	
	int solve(vector<int>& val, vector<int>& wt, int index, int W, vector<vector<int>> & dp) {
		if (index == val.size() || W == 0) {
			return 0;
			
		}
		
		if (dp[index][W] != -1) {
			
			return dp[index][W];
			
		}
		
		int take = 0;
		
		if (wt[index] <= W) {
			
			take = val[index] + solve(val, wt, index + 1, W - wt[index], dp);
			
		}
		
		int notTake = solve(val, wt, index + 1, W, dp);
		
		return dp[index][W] = max(take, notTake);
		
	}
	
	public:
	int knapsack(int W, vector<int> &val, vector<int> &wt) {
		
		vector<vector<int>> dp(val.size(), vector<int>(W + 1, -1));
		return solve(val, wt, 0, W, dp);
		
	}
};
