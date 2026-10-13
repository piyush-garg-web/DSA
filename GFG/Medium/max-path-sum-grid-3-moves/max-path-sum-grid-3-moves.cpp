class Solution {
	private:
	int solve(vector<vector<int>> & mat, int r, int c,
	vector<vector<int>> & dp) {
		
		int n = mat.size();
		int m = mat[0].size();
		
		if (c < 0 || c >= m)
			return 0;
		
		if (r == n - 1)
			return mat[r][c];
		
		if (dp[r][c] != -1)
			return dp[r][c];
		
		int left = 0, down = 0, right = 0;
		
		if (c > 0)
			left = solve(mat, r + 1, c - 1, dp);
		
		down = solve(mat, r + 1, c, dp);
		
		if (c < m - 1)
			right = solve(mat, r + 1, c + 1, dp);
		
		return dp[r][c] = mat[r][c] + max(left, max(down, right));
	}
	
	public:
	int maximumPath(vector<vector<int>> & mat) {
		
		int n = mat.size();
		int m = mat[0].size();
		
		vector<vector<int>> dp(n, vector<int>(m, -1));
		
		int ans = 0;
		
		for (int c = 0; c < m; c++) {
			ans = max(ans, solve(mat, 0, c, dp));
		}
		
		return ans;
	}
};
