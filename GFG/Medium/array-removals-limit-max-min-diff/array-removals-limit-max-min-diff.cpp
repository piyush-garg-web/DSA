class Solution {
	public:
	int removals(vector<int>& arr, int k) {
		
		sort (arr.begin(), arr.end());
		int i = 0;
		int ans = 0;
		
		for (int j = 0; j<arr.size(); j++) {
			
			while (arr[j]-arr[i]>k) {
				
				i++;
			}
			
			ans = max(ans, j - i + 1);
		}
		
		return arr.size() - ans;
		
	}
};
