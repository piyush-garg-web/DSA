class Solution {
	long long solve (int n, int r) {
		
		if (r == 0) {
			
			return 1;
		}
		
		if (r>n) {
			
			return 0;
		}
		
		return n*solve(n - 1, r - 1);
	}
	
	public:
	long long nPr(int n, int r) {
		
		return solve (n, r);
		
	}
};
