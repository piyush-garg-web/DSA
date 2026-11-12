class Solution {
	private:
	int solve (vector<vector<int>> & a, vector<vector<int>> & t, vector<int>& e,
	vector<int>& x, int line, int station, vector<vector<int>> & dp) {
		
		if (station == a[0].size() - 1) {
			
			return a[line][station]+x[line];
		}
		
		if (dp[line][station] != -1) {
			
			return dp[line][station];
		}
		
		int same = a[line][station]+solve(a, t, e, x, line, station + 1, dp);
		int change = a[line][station]+t[line][station + 1]+solve(a, t, e, x, 1 - line, station + 1, dp);
		
		return dp[line][station] = min(same, change);
		
	}
	
	public:
	int carAssembly(vector<vector<int>> & a, vector<vector<int>> & t, vector<int>& e,
	vector<int>& x) {
		
		vector<vector<int>> dp (2, vector<int> (a[0].size() + 1, -1));
		
		int line1 = e[0]+solve(a, t, e, x, 0, 0, dp);
		int line2 = e[1]+solve(a, t, e, x, 1, 0, dp);
		
		return min(line1, line2);
		
	}
};
