class Solution {
	public:
	int maxSubstring(string &s) {
		
		int sum = 0;
		int maxi = INT_MIN;
		
		for (int i = 0; i<s.size(); i++) {
			
			if (s[i] == '0') {
				
				sum += 1;
			}
			
			else {
				
				sum += -1;
			}
			
			maxi = max(maxi, sum);
			
			if (sum<0) {
				
				sum = 0;
			}
		}
		
		return maxi;
		
	}
};
