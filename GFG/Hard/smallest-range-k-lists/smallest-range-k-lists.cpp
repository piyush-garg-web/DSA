class Solution {
	public:
	vector<int> findSmallestRange(vector<vector<int>> & mat) {
		
		int n = mat.size();
		int k = mat[0].size();
		
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		
		int mini = INT_MAX;
		int maxi = INT_MIN;
		
		for (int i = 0; i<n; i++) {
			
			mini = min(mini, mat[i][0]);
			maxi = max(maxi, mat[i][0]);
			
			pq.push({mat[i][0], {i, 0}});
		}
		
		int start = mini;
		int end = maxi;
		
		while (!pq.empty()) {
			
			auto it = pq.top();
			pq.pop();
			
			int val = it.first;
			int row = it.second.first;
			int col = it.second.second;
			
			mini = val;
			
			if (maxi - mini < end - start || (maxi - mini == end - start) && (mini<start)) {
				
				start = mini;
				end = maxi;
			}
			
			if (col + 1 < k) {
				
				pq.push({mat[row][col + 1], {row, col + 1}});
				maxi = max(maxi, mat[row][col + 1]);
			}
			
			else {
				
				break;
			}
			
		}
		
		return {start, end};
	}
};
