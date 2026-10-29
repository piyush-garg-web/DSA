class Solution {
	private:
	int solve (string& s1, string& s2, int i, int j, vector<vector<int>> & dp) {
		
		if (i == s1.length()) {
			
			return s2.length() - j;
		}
		
		if (j == s2.length()) {
			
			return s1.length() - i;
		}
		
		if (dp[i][j] != -1) {
			
			return dp[i][j];
		}
		
		if (s1[i] == s2[j]) {
			
			return dp[i][j] = solve (s1, s2, i + 1, j + 1, dp);
			
		}
		
		int ans = 0;
		
		int insert = 1 + solve(s1, s2, i, j + 1, dp);
		
		int del = 1 + solve(s1, s2, i + 1, j, dp);
		
		int replace = 1 + solve(s1, s2, i + 1, j + 1, dp);
		
		ans = min(insert, min(del, replace));
		
		return dp[i][j] = ans;
	}
	
	public:
	int editDistance(string& s1, string& s2) {
		
		vector<vector<int>> dp (s1.length(), vector<int> (s2.length(), -1));
		return solve (s1, s2, 0, 0, dp);
		
	}
};
