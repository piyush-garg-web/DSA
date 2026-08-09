class Solution {
	public:
	long long maxSum(vector<int>& arr) {
		
		sort(arr.begin(), arr.end());
		int i = 0;
		int j = arr.size() - 1;
		long long sum = 0;
		
		while (i<j) {
			
			sum += arr[j]-arr[i];
			sum += arr[j]-arr[i + 1];
			i++;
			j--;
		}
		
		sum += arr[arr.size()/2]-arr[0];
		
		return sum;
		
	}
};
