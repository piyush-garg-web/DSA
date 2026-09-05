class Solution {
	private:
	void bfs (int row, int col, vector<vector<int>> & visited, vector<vector<char>> & grid, int n, int m) {
		
		queue<pair<int, int>> q;
		
		visited[row][col] = 1;
		q.push({row, col});
		
		while (!q.empty()) {
			
			auto top = q.front();
			q.pop();
			
			int r = top.first;
			int c = top.second;
			
			for (int nR = -1; nR <= 1; nR++) {
				
				for (int nC = -1; nC <= 1; nC++) {
					
					int newR = r + nR;
					int newC = c + nC;
					
					if (newR >= 0 && newR<n && newC >= 0 && newC<m && visited[newR][newC] == 0 && grid[newR][newC] == 'L') {
						
						visited[newR][newC] = 1;
						q.push({newR, newC});
					}
				}
			}
		}
	}
	
	public:
	int countIslands(vector<vector<char>> & grid) {
		
		int n = grid.size();
		int m = grid[0].size();
		
		vector<vector<int>> visited (n, vector<int> (m, 0));
		int count = 0;
		
		for (int i = 0; i<n; i++) {
			
			for (int j = 0; j<m; j++) {
				
				if (!visited[i][j] && grid[i][j] == 'L') {
					
					count++;
					bfs(i, j, visited, grid, n, m);
				}
			}
		}
		
		return count;
		
	}
};
