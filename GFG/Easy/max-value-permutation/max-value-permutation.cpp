class Solution {
	public:
	int maxValue(vector<int> &arr) {
		
		int ans = 0;
		
		sort(arr.begin(), arr.end());
		
		for (int i = 0; i<arr.size(); i++) {
			
			ans = ans + arr[i]*i;
		}
		
		return ans;
		
	}
};
