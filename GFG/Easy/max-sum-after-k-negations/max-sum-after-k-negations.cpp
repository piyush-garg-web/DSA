class Solution {
	public:
	int maximizeSum(vector<int>& arr, int k) {
		
		sort(arr.begin(), arr.end());
		
		int i = 0;
		
		while (k>0 && arr[i] <= 0 && i<arr.size()) {
			arr[i] = -arr[i];
			i++;
			k--;
		}
		
		int sum = 0;
		int mini = INT_MAX;
		
		for (int x:arr) {
			sum += x;
			mini = min(mini, x);
		}
		
		if (k%2 == 1) {
			sum -= 2*mini;
		}
		
		return sum;
		
	}
};
