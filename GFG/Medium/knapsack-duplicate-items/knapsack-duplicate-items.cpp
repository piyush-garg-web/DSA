class Solution {
	private:
	int solve(vector<int>& val, vector<int>& wt, int capacity, int index, int n, vector<vector<int>> & dp) {
		
		if (capacity == 0) {
			
			return 0;
		}
		
		if (capacity<0 || index == n) {
			
			return 0;
		}
		
		if (dp[capacity][index] != -1) {
			
			return dp[capacity][index];
		}
		
		int take = 0;
		
		if (wt[index] <= capacity) {
			
			take = val[index]+solve(val, wt, capacity - wt[index], index, n, dp);
		}
		
		int notTake = solve(val, wt, capacity, index + 1, n, dp);
		
		return dp[capacity][index] = max(take, notTake);
	}
	
	public:
	int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
		
		int n = val.size();
		vector<vector<int>> dp (capacity + 1, vector<int> (n + 1, -1));
		return solve(val, wt, capacity, 0, n, dp);
		
	}
};
