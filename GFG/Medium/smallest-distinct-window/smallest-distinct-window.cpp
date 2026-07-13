class Solution {
	public:
	int findSubString(string& str) {
		
		int n = str.size();
		vector<int> freq (26, 0);
		int distinct = 0;
		
		for (int i = 0; i<n; i++) {
			if (freq[str[i]-'a'] == 0) {
				distinct++;
			}
			
			freq[str[i]-'a']++;
		}
		
		for (int i =0 ; i<26; i++) {
			freq[i] = 0;
		}
		
		int l = 0;
		int r = 0;
		int mini = INT_MAX;
		int count = 0;
		
		while (r<n) {
			if (freq[str[r]-'a'] == 0) {
				count++;
			}
			
			freq[str[r]-'a']++;
			
			while (count == distinct) {
				
				if (r - l + 1 < mini) {
					mini = min(mini, r - l + 1);
				}
				
				freq[str[l]-'a']--;
				if (freq[str[l]-'a'] == 0) {
					count--;
				}
				
				l++;
			}
			
			r++;
			
		}
		
		return mini;
		
	}
};
