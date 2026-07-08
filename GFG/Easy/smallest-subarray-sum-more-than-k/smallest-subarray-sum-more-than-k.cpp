class Solution {
	public:
	int smallestSubWithSum(int x, vector<int>& arr) {
		int sum = 0;
		int ans = INT_MAX;
		int left = 0;
		
		for (int right = 0; right<arr.size(); right++) {
			sum += arr[right];
			
			while (sum>x) {
				ans = min(ans, right - left + 1);
				sum -= arr[left];
				left++;
			}
		}
		
		if (ans == INT_MAX) {
			return 0;
		}
		
		else {
			return ans;
		}
	}
};
