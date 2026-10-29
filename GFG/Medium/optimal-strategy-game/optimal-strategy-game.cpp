class Solution {
	private:
	int solve (int i, int j, vector<int>& arr, vector<vector<int>> & dp) {
		
		if (i>j) {
			
			return 0;
		}
		
		if (i == j) {
			
			return arr[i];
		}
		
		if (dp[i][j] != -1) {
			
			return dp[i][j];
		}
		
		int first = arr[i] + min(solve(i + 2, j, arr, dp), solve(i + 1, j - 1, arr, dp));
		int last = arr[j]+min(solve(i + 1, j - 1, arr, dp), solve(i, j - 2, arr, dp));
		
		return dp[i][j] = max(first, last);
	}
	
	public:
	int maximumAmount(vector<int> &arr) {
		
		int n = arr.size();
		vector<vector<int>> dp (n + 1, vector<int> (n + 1, -1));
		return solve (0, n - 1, arr, dp);
		
	}
};
