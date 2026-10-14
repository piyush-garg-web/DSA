class Solution {
	int solve (vector<int>& cost, int w, int index, vector<vector<int>> & dp) {
		
		if (w == 0) {
			
			return 0;
		}
		
		if (index == cost.size() || w<0) {
			
			return 1e9;
		}
		
		if (dp[w][index] != -1) {
			
			return dp[w][index];
		}
		
		int take = 1e9;
		
		if (cost[index] != -1 && index + 1 <= w) {
			
			take = cost[index]+solve(cost, w - (index + 1), index, dp);
		}
		
		int notTake = solve(cost, w, index + 1, dp);
		
		return dp[w][index] = min(take, notTake);
	}
	
	public:
	int minimumCost(vector<int> &cost, int w) {
		
		vector<vector<int>> dp (w + 1, vector<int> (cost.size() + 1, -1));
		
		int ans = solve(cost, w, 0, dp);
		
		if (ans >= 1e9) {
			
			return - 1;
		}
		
		return ans;
		
	}
};
