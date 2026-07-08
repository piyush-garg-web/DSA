class Solution {
	public:
	int minSwap(vector<int>& arr, int k) {
		
		int good = 0;
		
		for (int i = 0; i<arr.size(); i++) {
			if (arr[i] <= k) {
				good++;
			}
		}
		
		int bad = 0;
		
		for (int i = 0; i<good; i++) {
			if (arr[i]>k) {
				bad++;
			}
		}
		
		int ans = bad;
		int l = 0;
		int r = good;
		
		while (r<arr.size()) {
			
			if (arr[l]>k) {
				bad--;
			}
			
			if (arr[r]>k) {
				bad++;
			}
			
			ans = min(ans, bad);
			
			l++;
			r++;
		}
		
		return ans;
		
	}
};
