class Solution {
	public:
	vector<int> mergeArrays(vector<vector<int>> &mat) {
		
		int n = mat.size();
		int m = mat[0].size();
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		
		for (int i = 0; i<n; i++) {
			
			pq.push({mat[i][0], {i, 0}});
		}
		
		vector<int> ans;
		
		while (!pq.empty()) {
			
			auto top = pq.top();
			pq.pop();
			
			int val = top.first;
			int row = top.second.first;
			int col = top.second.second;
			
			ans.push_back(val);
			
			if (col + 1 <m) {
				
				pq.push({mat[row][col + 1], {row, col + 1}});
			}
		}
		
		return ans;
		
	}
};
