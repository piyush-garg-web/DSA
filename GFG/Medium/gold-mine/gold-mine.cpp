class Solution {
	private:
	int solve (vector<vector<int>> & mat, int row, int col, vector<vector<int>> & dp) {
		
		int n = mat.size();
		int m = mat[0].size();
		
		if (col == m - 1) {
			
			return mat[row][col];
		}
		
		if (dp[row][col] != -1) {
			
			return dp[row][col];
		}
		
		int right = 0;
		int diagUp = 0;
		int diagDown = 0;
		
		right = solve(mat, row, col + 1, dp);
		
		if (row - 1 >= 0) {
			
			diagUp = solve(mat, row - 1, col + 1, dp);
		}
		
		if (row + 1<n) {
			
			diagDown = solve(mat, row + 1, col + 1, dp);
		}
		
		return dp[row][col] = mat[row][col]+max(right, max(diagUp, diagDown));
		
	}
	
	public:
	int maxGold(vector<vector<int>> & mat) {
		
		int n = mat.size();
		int m = mat[0].size();
		
		vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));
		
		int ans = 0;
		
		for (int i = 0; i<n; i++) {
			
			ans = max(ans, solve(mat, i, 0, dp));
		}
		
		return ans;
		
	}
};
