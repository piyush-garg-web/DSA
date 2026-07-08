class Solution {
	public:
	int countTriplets(int sum, vector<int>& arr) {
		
		int n = arr.size();
		int count = 0;
		sort(arr.begin(), arr.end());
		
		for (int i = 0; i<n - 2; i++) {
			
			int left = i + 1;
			int right = n - 1;
			
			while (left<right) {
				
				int actualSum = arr[i]+arr[left]+arr[right];
				
				if (actualSum<sum) {
					count += right - left;
					left++;
				}
				
				else {
					right--;
				}
			}
		}
		
		return count;
		
	}
};
