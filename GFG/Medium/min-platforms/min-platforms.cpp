class Solution {
	public:
	int minPlatform(vector<int>& arr, vector<int>& dep) {
		
		sort(arr.begin(), arr.end());
		sort(dep.begin(), dep.end());
		
		int i = 0;
		int j = 0;
		int count = 0;
		int maxCount = 0;
		int n = arr.size();
		
		while (i<n && j<n) {
			
			if (arr[i] <= dep[j]) {
				count++;
				i++;
			}
			
			else {
				count--;
				j++;
			}
			
			maxCount = max(maxCount, count);
		}
		
		return maxCount;
		
	}
};
