class Solution {
	public:
	int maxProduct(vector<int> &arr) {
		int maxP = arr[0];
		int minP = arr[0];
		int ans = arr[0];
		
		for (int i = 1; i<arr.size(); i++) {
			if (arr[i]<0) {
				swap(maxP, minP);
			}
			
			maxP = max(arr[i], arr[i]*maxP);
			minP = min(arr[i], arr[i]*minP);
			
			ans = max(ans, maxP);
		}
		
		return ans;
		
	}
};
