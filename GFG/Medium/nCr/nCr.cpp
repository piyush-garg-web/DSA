class Solution {
	private:
	int solve (int n, int r, vector<vector<int>> & dp) {
		
		if (r == 0 || n == r) {
			
			return 1;
		}
		
		if (r>n) {
			
			return 0;
		}
		
		if (dp[n][r] != -1) {
			
			return dp[n][r];
		}
		
		int include = solve(n - 1, r - 1, dp);
		int exclude = solve(n - 1, r, dp);
		
		return dp[n][r] = include + exclude;
		
	}
	
	public:
	int nCr(int n, int r) {
		
		vector<vector<int>> dp (n + 1, vector<int> (r + 1, -1));
		return solve (n, r, dp);
		
	}
};
