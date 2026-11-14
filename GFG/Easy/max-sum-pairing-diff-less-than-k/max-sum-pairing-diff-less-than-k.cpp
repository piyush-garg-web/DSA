class Solution {
	private:
	int solve (vector<int>& arr, int index, int k, vector<int>& dp) {
		
		if (index >= arr.size()) {
			
			return 0;
		}
		
		if (dp[index] != -1) {
			
			return dp[index];
		}
		
		int exclude = solve(arr, index + 1, k, dp);
		
		int include = 0;
		
		if (index + 1<arr.size() && arr[index + 1]-arr[index]<k) {
			
			include = arr[index]+arr[index + 1]+solve(arr, index + 2, k, dp);
		}
		
		return dp[index] = max(include, exclude);
	}
	
	public:
	int sumDiffPairs(vector<int>& arr, int k) {
		
		sort(arr.begin(), arr.end());
		vector<int> dp (arr.size() + 1, -1);
		return solve(arr, 0, k, dp);
		
	}
};
