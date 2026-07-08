class Solution {
	public:
	int romanToDecimal(string &s) {
		
		unordered_map<char, int> map;
		
		map['I'] = 1;
		map['V'] = 5;
		map['X'] = 10;
		map['L'] = 50;
		map['C'] = 100;
		map['D'] = 500;
		map['M'] = 1000;
		
		int i = 0;
		int ans = 0;
		
		while (i<s.size()) {
			if (i + 1<s.size() && map[s[i + 1]]>map[s[i]]) {
				ans += map[s[i + 1]]-map[s[i]];
				i += 2;
			}
			else {
				ans += map[s[i]];
				i++;
			}
		}
		
		return ans;
		
	}
};
