class Solution {
	public:
	vector<vector<int>> nearest(vector<vector<int>> & grid) {
		
		int n = grid.size();
		int m = grid[0].size();
		
		queue<pair<int, int>> q;
		vector<vector<int>> ans (n, vector<int> (m, -1));
		
		for (int i = 0; i<n; i++) {
			
			for (int j = 0; j<m; j++) {
				
				if (grid[i][j] == 1) {
					
					ans[i][j] = 0;
					q.push({i, j});
				}
			}
		}
		
		int x[] = {-1, 0, 1, 0};
		int y[] = {0, 1, 0, -1};
		
		while (!q.empty()) {
			
			auto it = q.front();
			q.pop();
			
			for (int i = 0; i<4; i++) {
				
				int newX = it.first + x[i];
				int newY = it.second + y[i];
				
				if (newX >= 0 && newX<n && newY >= 0 && newY<m && ans[newX][newY] == -1) {
					
					ans[newX][newY] = ans[it.first][it.second]+1;
					q.push({newX, newY});
				}
			}
		}
		
		return ans;
		
	}
};
