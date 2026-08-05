class Solution {
	public:
	int minSubset(vector<int> &arr) {
		
		if (arr.size() == 1) {
			return 1;
		}
		
		sort(arr.begin(), arr.end());
		int sum = 0;
		
		for (int i = 0; i<arr.size(); i++) {
			sum += arr[i];
		}
		
		int ans = 0;
		int i = arr.size() - 1;
		int currSum = 0;
		
		while (i >= 0) {
			ans++;
			sum -= arr[i];
			currSum += arr[i];
			if (currSum>sum) {
				break;
			}
			
			i--;
		}
		
		return ans;
		
	}
};
