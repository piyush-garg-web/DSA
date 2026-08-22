class Solution {
	public:
	int minValue(string &s, int k) {
		
		unordered_map<char, int> mp;
		
		for (char ch : s) {
			
			mp[ch]++;
		}
		
		priority_queue<int> pq;
		
		for (auto it : mp) {
			
			pq.push(it.second);
		}
		
		while (k>0) {
			
			int freq = pq.top();
			pq.pop();
			
			freq--;
			k--;
			
			if (freq>0) {
				
				pq.push(freq);
			}
		}
		
		int ans = 0;
		
		while (!pq.empty()) {
			
			int freq = pq.top();
			pq.pop();
			
			ans += freq*freq;
		}
		
		return ans;
		
	}
};
