class Solution {
	public:
	bool subArrayExists(vector<int>& arr) {
		unordered_map<int, int> mp;
		mp[0] = 1;
		
		int pSum = 0;
		for (int x:arr) {
			pSum += x;
			
			if (mp.count(pSum)) {
				return true;
			}
			
			mp[pSum]++;
			
		}
		
		return false;
		
	}
};
