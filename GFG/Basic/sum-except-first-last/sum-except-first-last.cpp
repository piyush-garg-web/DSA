class Solution {
	public:
	int sumExceptFirstLast(vector<int>& arr) {
		
		int n = arr.size();
		
		if (n <= 2) {
			
			return 0;
		}
		
		int sum = 0;
		
		for (int i = 0; i<n; i++) {
			
			sum += arr[i];
		}
		
		return sum - arr[0]-arr[n - 1];
		
	}
};
