class Solution {
	private:
	bool isSafe(int row, int col, vector<vector<int>> & visited, int n) {
		
		for (int i = 0; i<row; i++) {
			if (visited[i][col] == 1) {
				return false;
			}
		}
		
		int i = row - 1;
		int j = col - 1;
		
		while (i >= 0 && j >= 0) {
			if (visited[i][j] == 1) {
				return false;
			}
			
			i--;
			j--;
		}
		
		i = row - 1;
		j = col + 1;
		
		while (i >= 0 && j<n) {
			if (visited[i][j] == 1) {
				return false;
			}
			
			i--;
			j++;
		}
		
		return true;
		
	}
	
	void solve (int row, vector<int>& temp, vector<vector<int>> & ans, vector<vector<int>> & visited, int n) {
		
		if (row == n) {
			ans.push_back(temp);
			return;
		}
		
		for (int col = 0; col<n; col++) {
			
			if (isSafe(row, col, visited, n)) {
				
				temp.push_back(col + 1);
				visited[row][col] = 1;
				
				solve (row + 1, temp, ans, visited, n);
				
				temp.pop_back();
				visited[row][col] = 0;
			}
		}
		
	}
	
	public:
	vector<vector<int>> nQueen(int n) {
		
		vector<int> temp;
		vector<vector<int>> visited (n, vector<int> (n, 0));
		vector<vector<int>> ans;
		
		solve (0, temp, ans, visited, n);
		return ans;
		
	}
};
