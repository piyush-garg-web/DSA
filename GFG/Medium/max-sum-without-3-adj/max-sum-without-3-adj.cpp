class Solution {
	private:
	int solve (vector<int>& arr, int index, int count, vector<vector<int>> & dp) {
		
		if (index == arr.size()) {
			
			return 0;
		}
		
		if (dp[index][count] != -1) {
			
			return dp[index][count];
			
		}
		
		int notTake = solve(arr, index + 1, 0, dp);
		
		int take = 0;
		
		if (count<2) {
			
			take = arr[index]+solve(arr, index + 1, count + 1, dp);
		}
		
		return dp[index][count] = max(take, notTake);
		
	}
	
	public:
	int findMaxSum(vector<int>& arr) {
		
		vector<vector<int>> dp (arr.size() + 1, vector<int> (3, -1));
		return solve (arr, 0, 0, dp);
		
	}
};
