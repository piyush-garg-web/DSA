class Solution {
	public:
	vector<double> getMedian(vector<int> &arr) {
		
		vector<double> ans;
		priority_queue<int> maxi;
		priority_queue<int, vector<int>, greater<int>> mini;
		
		for (int x : arr) {
			
			if (maxi.empty() || x <= maxi.top()) {
				
				maxi.push(x);
			}
			
			else {
				
				mini.push(x);
			}
			
			if (maxi.size() > mini.size() + 1) {
				
				mini.push(maxi.top());
				maxi.pop();
			}
			
			else if (mini.size() > maxi.size()) {
				
				maxi.push(mini.top());
				mini.pop();
			}
			
			if (maxi.size() == mini.size()) {
				
				double median = (maxi.top() + mini.top())/2.0;
				ans.push_back(median);
			}
			
			else {
				
				ans.push_back(maxi.top()/1.0);
			}
		}
		
		return ans;
		
	}
};
