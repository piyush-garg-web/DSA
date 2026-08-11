class Solution {
	private:
	bool solve (vector<int>& arr, int total, int n) {
		
		vector<int> curr (total + 1, 0);
		vector<int> next (total + 1, 0);
		
		curr[0] = 1;
		next[0] = 1;
		
		for (int i = n - 1 ; i >= 0; i--) {
			
			for (int j = 0; j <= total; j++) {
				
				bool inc = 0;
				
				if (j - arr[i] >= 0) {
					
					inc = next[j - arr[i]];
				}
				
				bool exc = next[j];
				
				curr[j] = inc || exc;
			}
			
			next=curr;
		}
		
		return next[total];
		
	}
	
	public:
	bool equalPartition(vector<int>& arr) {
		
		int sum = 0;
		int n = arr.size();
		
		for (int x:arr) {
			sum += x;
		}
		
		if (sum%2 == 1) {
			
			return false;
		}
		
		return solve (arr, sum/2, n);
		
	}
};
