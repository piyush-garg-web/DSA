class Solution {
	private:
	int solve (vector<vector<int>> & mat, int i, int j, int& maxi, vector<vector<int>> & dp) {
		
		if (i >= mat.size() || j >= mat[0].size()) {
			
			return 0;
		}
		
		if (dp[i][j] != -1) {
			
			return dp[i][j];
		}
		
		int right = solve(mat, i, j + 1, maxi, dp);
		int down = solve(mat, i + 1, j, maxi, dp);
		int diag = solve(mat, i + 1, j + 1, maxi, dp);
		
		if (mat[i][j] == 1) {
			
			int ans = 1 + min(right, min(down, diag));
			maxi = max(maxi, ans);
			return dp[i][j] = ans;
			
		}
		
		else {
			
			return dp[i][j] = 0;
		}
	}
	
	public:
	int maxSquare(vector<vector<int>> & mat) {
		
		int n = mat.size();
		int m = mat[0].size();
		
		vector<vector<int>> dp (n + 1, vector<int> (m + 1, -1));
		int maxi = 0;
		solve(mat, 0, 0, maxi, dp);
		return maxi;
		
	}
};
