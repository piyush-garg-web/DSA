class Solution {
	public:
	bool hasTripletSum(vector<int> &arr, int target) {
		
		sort(arr.begin(), arr.end());
		int n = arr.size();
		
		for (int i = 0; i<n - 2; i++) {
			int element = arr[i];
			int left = i + 1;
			int right = n - 1;
			
			while (left<right) {
				int sum = element+arr[left]+arr[right];
				if (sum == target) {
					return true;
				}
				
				else if (sum<target) {
					left++;
				}
				
				else {
					right--;
				}
			}
		}
		return false;
	}
};