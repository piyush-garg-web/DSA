class Solution {
	public:
	int findMaxSum(vector<int>& arr) {
		
		int n = arr.size();
		
		int next1 = 0;
		int next2 = 0;
		
		for (int i = n - 1; i >= 0; i--) {
			
			int take = arr[i]+next2;
			int skip = next1;
			
			int curr = max (take, skip);
			
			next2 = next1;
			next1 = curr;
			
		}
		
		return next1;
		
	}
};
