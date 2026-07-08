class Solution {
	public:
	int findSubarray(vector<int> &arr) {
		
		unordered_map<int, int> mp;
		int count = 0;
		int sum = 0;
		mp[0] = 1;
		
		for (int x :arr) {
			sum += x;
			
			if (mp[sum] >= 1) {
				count +=mp[sum];
			}
			
			mp[sum]++;
			
		}
		
		return count;
		
	}
};
