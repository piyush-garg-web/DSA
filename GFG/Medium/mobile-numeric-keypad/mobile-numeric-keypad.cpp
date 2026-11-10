class Solution {
	private:
	int solve (int n, int i, unordered_map<int, vector<int>> & mp, vector<vector<int>> & dp) {
		
		if (n == 0) {
			
			return 1;
		}
		
		if (dp[n][i] != -1) {
			
			return dp[n][i];
		}
		
		int ans = 0;
		
		for (auto it : mp[i]) {
			
			ans += solve(n - 1, it, mp, dp);
		}
		
		return dp[n][i] = ans;
	}
	
	public:
	unordered_map<int, vector<int>> mp = {
		{0, {0, 8}},
		{1, {1, 2, 4}},
		{2, {2, 1, 3, 5}},
		{3, {3, 2, 6}},
		{4, {4, 1, 5, 7}},
		{5, {5, 2, 4, 6, 8}},
		{6, {6, 3, 5, 9}},
		{7, {7, 4, 8}},
		{8, {8, 5, 7, 9, 0}},
		{9, {9, 6, 8}}
	};
	
	int getCount(int n) {
		
		vector<vector<int>> dp (n + 1, vector<int> (11, -1));
		int ans = 0;
		
		for (int i = 0; i <= 9; i++) {
			
			ans += solve(n - 1, i, mp, dp);
		}
		
		return ans;
		
	}
};
