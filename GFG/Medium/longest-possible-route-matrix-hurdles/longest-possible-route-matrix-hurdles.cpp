class Solution {
	private:
	bool isSafe(vector<vector<int>> & mat, vector<vector<int>> & visited, int x, int y, int n, int m) {
		
		if (x >= 0 && x<n && y >= 0 && y<m && visited[x][y] != 1 && mat[x][y] == 1) {
			return true;
		}
		
		return false;
	}
	
	int solve (vector<vector<int>> & mat, vector<vector<int>> & visited, int n, int m, int x, int y, int xd, int yd) {
		
		if (x == xd && y == yd) {
			return 0;
		}
		
		visited[x][y] = 1;
		int maxi = -1;
		
		int newX = x + 1;
		int newY = y;
		
		if (isSafe(mat, visited, newX, newY, n, m)) {
			
			int ans = solve(mat, visited, n, m, newX, newY, xd, yd);
			
			if (ans != -1) {
				maxi = max(maxi, 1 + ans);
			}
		}
		
		newX = x;
		newY = y - 1;
		
		if (isSafe(mat, visited, newX, newY, n, m)) {
			
			int ans = solve(mat, visited, n, m, newX, newY, xd, yd);
			
			if (ans != -1) {
				maxi = max(maxi, 1 + ans);
			}
		}
		
		newX = x;
		newY = y + 1;
		
		if (isSafe(mat, visited, newX, newY, n, m)) {
			
			int ans = solve(mat, visited, n, m, newX, newY, xd, yd);
			
			if (ans != -1) {
				maxi = max(maxi, 1 + ans);
			}
		}
		
		newX = x - 1;
		newY = y;
		
		if (isSafe(mat, visited, newX, newY, n, m)) {
			
			int ans = solve(mat, visited, n, m, newX, newY, xd, yd);
			
			if (ans != -1) {
				maxi = max(maxi, 1 + ans);
			}
		}
		
		visited[x][y] = 0;
		
		return maxi;
		
	}
	
	public:
	int longestPath(vector<vector<int>> & mat, int xs, int ys, int xd, int yd) {
		
		int n = mat.size();
		int m = mat[0].size();
		
		if (mat[xs][ys] == 0 || mat[xd][yd] == 0) {
			return - 1;
		}
		
		vector<vector<int>> visited (n, vector<int> (m, 0));
		
		return solve (mat, visited, n, m, xs, ys, xd, yd);
		
	}
};
