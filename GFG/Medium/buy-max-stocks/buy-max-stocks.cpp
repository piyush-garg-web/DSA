class Solution {
	public:
	int buyMaximumProducts(int k, vector<int> price) {
		
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		
		for (int i = 0; i<price.size(); i++) {
			pq.push({price[i], i + 1});
		}
		
		int ans = 0;
		
		while (!pq.empty()) {
			
			auto top = pq.top();
			pq.pop();
			
			int count = min(top.second, k/top.first);
			ans += count;
			k -= count*top.first;
		}
		
		return ans;
		
	}
};
