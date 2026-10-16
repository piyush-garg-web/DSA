class Solution {
	private:
	int solve (string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<vector<int>>>& dp) {
		
		if (i == s1.size() || j == s2.size() || k == s3.size()) {
			
			return 0;
		}
		
		if (dp[i][j][k] != -1) {
			
			return dp[i][j][k];
		}
		
		if (s1[i] == s2[j] && s2[j] == s3[k]) {
			
			return dp[i][j][k] = 1 + solve(s1, s2, s3, i + 1, j + 1, k + 1, dp);
		}
		
		return dp[i][j][k] = max(solve(s1, s2, s3, i + 1, j, k, dp), max(solve(s1, s2, s3, i, j + 1, k, dp), solve(s1, s2, s3, i, j, k + 1, dp)));
	}
	public:
	int lcsOf3(string& s1, string& s2, string& s3) {
		
		int n = s1.size();
		int m = s2.size();
		int p = s3.size();
		
		vector<vector<vector<int>> > dp (n + 1, vector<vector<int>> (m + 1, vector<int> (p + 1, -1)));
		return solve (s1, s2, s3, 0, 0, 0, dp);
		
	}
};
