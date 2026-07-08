class Solution {
	public:
	bool areIsomorphic(string &s1, string &s2) {
		
		vector<int> map1 (26, -1);
		vector<int> map2 (26, -1);
		
		for (int i = 0; i<s1.size(); i++) {
			
			int a = s1[i]-'a';
			int b = s2[i]-'a';
			
			if (map1[a] == -1 && map2[b] == -1) {
				map1[a] = b;
				map2[b] = a;
			}
			
			else if (map1[a] != b || map2[b] != a) {
				return false;
			}
			
		}
		
		return true;
		
	}
};

