class Solution {
	public:
	double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
		
		priority_queue<pair<double, int>> pq;
		
		for (int i = 0; i<val.size(); i++) {
			
			double ratio = (double)val[i]/wt[i];
			pq.push({ratio, i});
		}
		
		double ans = 0.0;
		
		while (!pq.empty() && capacity>0) {
			
			auto top = pq.top();
			
			double ratio = top.first;
			int index = top.second;
			
			pq.pop();
			
			if (wt[index] <= capacity) {
				ans += val[index];
				capacity -= wt[index];
			}
			
			else {
				ans += (double)capacity/wt[index]*val[index];
				capacity = 0;
			}
			
		}
		
		return ans;
		
	}
};
