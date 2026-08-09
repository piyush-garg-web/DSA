class Solution {
	public:
	string chooseSwap(string &s) {
		
		vector<int> firstIndex (26, -1);
		
		for (int i = 0; i<s.size(); i++) {
			
			if (firstIndex[s[i]-'a'] == -1) {
				
				firstIndex[s[i]- 'a'] = i;
			}
			
		}
		
		for (int i = 0; i<s.size(); i++) {
			
			for (char ch = 'a'; ch<s[i]; ch++) {
				
				if (firstIndex[ch - 'a']>i) {
					
					char current = s[i];
					
					for (char &c: s) {
						
						if (c == current) {
							c = ch;
						}
						
						else if (c == ch) {
							c = current;
						}
					}
					
					return s;
				}
			}
		}
		
		return s;
		
	}
};
