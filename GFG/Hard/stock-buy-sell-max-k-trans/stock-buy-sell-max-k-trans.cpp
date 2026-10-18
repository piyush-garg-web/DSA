class Solution {
	int solve (vector<int>& prices, int k, int index, int trans, vector<vector<int>> & dp) {
		
		if (index == prices.size() || trans == 2*k) {
			
			return 0;
		}
		
		if (dp[index][trans] != -1) {
			
			return dp[index][trans];
		}
		
		int profit = 0;
		
		if (trans%2 == 0) {
			
			int buy = -prices[index]+solve(prices, k, index + 1, trans + 1, dp);
			
			int skip = solve(prices, k, index + 1, trans, dp);
			
			profit = max(buy, skip);
		}
		
		else {
			
			int sell = prices[index]+solve(prices, k, index + 1, trans + 1, dp);
			
			int skip = solve(prices, k, index + 1, trans, dp);
			
			profit = max(sell, skip);
		}
		
		return dp[index][trans] = profit;
	}
	
	public:
	int maxProfit(vector<int>& prices, int k) {
		
		vector<vector<int>> dp (prices.size() + 1, vector<int> (2*k + 1, -1));
		return solve (prices, k, 0, 0, dp);
		
	}
};
