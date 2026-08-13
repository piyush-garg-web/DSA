class Solution {
	private:
	void solve (string& s, vector<string>& ans, int index) {
		
		if (index >= s.size()) {
			ans.push_back(s);
			return;
		}
		
		set<char> used;
		
		for (int i = index; i<s.size(); i++) {
			
			if (used.find(s[i]) != used.end()) {
				continue;
			}
			
			used.insert(s[i]);
			
			swap(s[index], s[i]);
			solve(s, ans, index + 1);
			swap(s[i], s[index]);
		}
	}
	
	public:
	vector<string> findPermutation(string &s) {
		
		vector<string> ans;
		sort(s.begin(), s.end());
		solve(s, ans, 0);
		return ans;
		
	}
};
