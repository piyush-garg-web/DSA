class Solution {
	public:
	vector<int> minMaxCandy(vector<int>& prices, int k) {
		
		vector<int> ans;
		sort(prices.begin(), prices.end());
		
		int n = prices.size();
		int mini = 0;
		int maxi = 0;
		
		int i = 0;
		int j = n - 1;
		
		while (i <= j) {
			mini += prices[i];
			i++;
			j -= k;
		}
		
		i = 0;
		j = n - 1;
		
		while (i <= j) {
			maxi += prices[j];
			j--;
			i += k;
		}
		
		ans.push_back(mini);
		ans.push_back(maxi);
		
		return ans;
		
	}
};
