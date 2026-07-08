class Solution {
	public:
	int minFlips(string& s) {
		
		int ans1 = 0;
		int ans2 = 0;
		
		for (int i = 0; i<s.size(); i++) {
			
			if (((i%2 == 0) && s[i] != '0') || ((i%2 == 1) && s[i] != '1')) {
				ans1++;
			}
			
			if (((i%2 == 0) && s[i] != '1') || ((i%2 == 1) && s[i] != '0')) {
				ans2++;
			}
		}
		
		return min (ans1, ans2);
		
	}
};
