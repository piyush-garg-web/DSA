class Solution {
	public:
	// Function to check if b is a subset of a
	bool isSubset(vector<int> &a, vector<int> &b) {
		unordered_map<int, int> map;
		
		for (int i = 0; i<a.size(); i++) {
			map[a[i]]++;
		}
		
		if (b.size()>a.size()) {
			return false;
		}
		
		for (int i = 0; i<b.size(); i++) {
			if (map[b[i]]==0) {
				return false;
			}
			
			map[b[i]]--;
		}
		
		return true;
		
	}
};
