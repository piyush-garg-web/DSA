class Solution {
	private:
	bool isSafe(int x, int y, int m, int n) {
		
		if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1) {
			return true;
		}
		
		else {
			return false;
		}
	}
	
	void solve (vector<vector<int>> & mat, vector<vector<int>> & ans, vector<int>& temp, int x, int y, int m, int n) {
		
		if (x == n - 1 && y == m - 1) {
			ans.push_back(temp);
			return;
		}
		
		int newX = x;
		int newY = y + 1;
		
		if (isSafe(newX, newY, m, n)) {
			
			temp.push_back(mat[newX][newY]);
			solve (mat, ans, temp, newX, newY, m, n);
			temp.pop_back();
		}
		
		newX = x + 1;
		newY = y;
		
		if (isSafe(newX, newY, m, n)) {
			
			temp.push_back(mat[newX][newY]);
			solve (mat, ans, temp, newX, newY, m, n);
			temp.pop_back();
		}
		
	}
	
	public:
	vector<vector<int>> allPaths(vector<vector<int>> & mat) {
		
		int n = mat.size();
		int m = mat[0].size();
		
		vector<vector<int>> ans;
		vector<int> temp;
		
		temp.push_back(mat[0][0]);
		
		solve(mat, ans, temp, 0, 0, m, n);
		
		return ans;
		
	}
};
