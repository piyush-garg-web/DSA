class Solution {
	private:
	int solve (int n) {
		
		if (n == 1) {
			
			return 0;
		}
		
		if (n == 2) {
			
			return 1;
		}
		
		return (n - 1)*(solve(n - 2) + solve(n - 1));
	}
	
	public:
	int derangeCount(int n) {
		
		return solve (n);
		
	}
};
