class Solution {
	private:
	int solve (string& s, int i, int j, vector<vector<int>> & dp) {
		
		if (i>j) {
			
			return 0;
		}
		
		if (i == j) {
			
			return 1;
		}
		
		if (dp[i][j] != -1) {
			
			return dp[i][j];
		}
		
		if (s[i] == s[j]) {
			
			return dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);
			
		}
		
		int skipL = solve(s, i + 1, j, dp);
		int skipR = solve(s, i, j - 1, dp);
		
		return dp[i][j] = max(skipL, skipR);
		
	}
	
	public:
	int longestPalinSubseq(string &s) {
		
		int n = s.size();
		vector<vector<int>> dp (n + 1, vector<int> (n + 1, -1));
		
		return solve (s, 0, s.size() - 1, dp);
		
	}
};
