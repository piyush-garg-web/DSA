class Solution {
	private:
	
	bool isSafe(int x, int y, vector<vector<int>> & visited, int n, vector<vector<int>> & maze) {
		
		if (x >= 0 && x <= n - 1 && y >= 0 && y <= n - 1 && visited[x][y] == 0 && maze[x][y] == 1) {
			return true;
		}
		
		else {
			return false;
		}
	}
	
	void solve (int n, vector<vector<int>> & maze, vector<vector<int>> & visited, int x, int y, string& path, vector<string>& ans) {
		
		if (x == n - 1 && y == n - 1) {
			ans.push_back(path);
			return;
		}
		
		visited[x][y] = 1;
		
		int newX = x + 1;
		int newY = y;
		
		if (isSafe(newX, newY, visited, n, maze)) {
			
			path.push_back('D');
			solve(n, maze, visited, newX, newY, path, ans);
			path.pop_back();
		}
		
		newX = x;
		newY = y - 1;
		
		if (isSafe(newX, newY, visited, n, maze)) {
			
			path.push_back('L');
			solve(n, maze, visited, newX, newY, path, ans);
			path.pop_back();
		}
		
		newX = x;
		newY = y + 1;
		
		if (isSafe(newX, newY, visited, n, maze)) {
			
			path.push_back('R');
			solve(n, maze, visited, newX, newY, path, ans);
			path.pop_back();
		}
		
		newX = x - 1;
		newY = y;
		
		if (isSafe(newX, newY, visited, n, maze)) {
			
			path.push_back('U');
			solve(n, maze, visited, newX, newY, path, ans);
			path.pop_back();
		}
		
		visited[x][y] = 0;
	}
	
	public:
	vector<string> ratInMaze(vector<vector<int>> & maze) {
		
		int n = maze.size();
		vector<vector<int>> visited (n, vector<int> (n, 0));
		
		vector<string> ans;
		string path = "";
		
		int x = 0;
		int y = 0;
		
		if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
			
			return ans;
		}
		
		solve(n, maze, visited, x, y, path, ans);
		return ans;
		
	}
};
