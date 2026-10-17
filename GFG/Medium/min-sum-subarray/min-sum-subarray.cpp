class Solution {
	public:
	int minSubarraySum(vector<int> &arr) {
		
		int sum = 0;
		int mini = INT_MAX;
		
		for (int i = 0; i<arr.size(); i++) {
			
			sum += arr[i];
			
			mini = min(mini, sum);
			
			if (sum>0) {
				
				sum = 0;
			}
		}
		
		return mini;
		
	}
};
