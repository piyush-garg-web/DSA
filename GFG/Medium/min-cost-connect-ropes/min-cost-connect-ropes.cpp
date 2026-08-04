class Solution {
	public:
	int minCost(vector<int>& arr) {
		
		priority_queue<int, vector<int>, greater<int>> pq;
		int ans = 0;
		
		for (int x:arr) {
			pq.push(x);
		}
		
		while (pq.size()>1) {
			
			int mini1 = pq.top();
			pq.pop();
			
			int mini2 = pq.top();
			pq.pop();
			
			int total = mini1 + mini2;
			ans += total;
			pq.push(total);
		}
		
		return ans;
		
	}
};
