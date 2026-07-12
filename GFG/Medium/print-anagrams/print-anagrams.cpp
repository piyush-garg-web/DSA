class Solution {
	public:
	vector<vector<string>> anagrams(vector<string>& arr) {
		
		unordered_map <string, vector<string>> map;
		
		for (string str :arr) {
			string key = str;
			sort(key.begin(), key.end());
			map[key].push_back(str);
		}
		
		vector<vector<string>> ans (map.size());
		
		int index = 0;
		
		for (auto it:map) {
			auto vec = it.second;
			for (int i = 0; i<vec.size(); i++) {
				ans[index].push_back(vec[i]);
			}
			
			index++;
		}
		
		return ans;
		
	}
};
