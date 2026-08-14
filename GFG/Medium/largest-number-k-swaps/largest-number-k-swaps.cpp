class Solution {
	private:
	void solve (string& s, string& ans, int k, int index) {
		
		if (k == 0 || index >= s.size()) {
			
			ans = max(ans, s);
			return;
		}
		
		char maxi = s[index];
		
		for (int i = index + 1; i<s.size(); i++) {
			maxi = max(maxi, s[i]);
		}
		
		if (s[index] == maxi) {
			solve(s, ans, k, index + 1);
		}
		
		for (int i = index + 1; i<s.size(); i++) {
			
			if (s[i] == maxi) {
				
				swap(s[index], s[i]);
				solve(s, ans, k - 1, index + 1);
				swap(s[i], s[index]);
			}
		}
	}
	
	public:
	string findMaximumNum(string& s, int k) {
		
		string ans = s;
		solve(s, ans, k, 0);
		return ans;
	}
};
