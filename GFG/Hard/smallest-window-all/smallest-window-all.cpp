class Solution {
	public:
	string minWindow(string &s, string &p) {
		
		int n = s.size();
		int m = p.size();
		vector<int> freq (26, 0);
		
		for (int i = 0; i<m; i++) {
			int index = p[i]-'a';
			freq[index]++;
		}
		
		int l = 0;
		int r = 0;
		int mini = INT_MAX;
		int sIndex = -1;
		int count = 0;
		
		while (r<n) {
			if (freq[s[r]-'a']>0) {
				count++;
			}
			
			freq[s[r]-'a']--;
			
			while (count == m) {
				if (r-l+1 <mini) {
					mini = min(mini, r - l + 1);
					sIndex = l;
				}
				
				freq[s[l]-'a']++;
				if (freq[s[l]-'a']> 0) {
					count--;
				}
				
				l++;
			}
			
			r++;
		}
		
		string ans = "";
		
		if (sIndex == -1) {
			return ans;
		}
		
		else {
			
			for (int i = sIndex; i<sIndex+mini; i++) {
				ans += s[i];
			}
			
			return ans;
		}
		
	}
};
