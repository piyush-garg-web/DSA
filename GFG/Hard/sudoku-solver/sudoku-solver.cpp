class Solution {
	
	private:
	
	bool isSafe(int row, int col, int num, vector<vector<int>> & mat) {
		
		for (int i = 0; i<9; i++) {
			
			if (mat[row][i] == num) {
				
				return false;
				
			}
			
		}
		
		for (int i = 0; i<9; i++) {
			
			if (mat[i][col] == num) {
				
				return false;
				
			}
			
		}
		
		int startRow = (row/3)*3;
		
		int startCol = (col/3)*3;
		
		for (int i = startRow; i<startRow + 3; i++) {
			
			for (int j = startCol; j<startCol + 3; j++) {
				
				if (mat[i][j] == num) {
					
					return false;
					
				}
				
			}
			
		}
		
		return true;
		
	}
	
	bool solve (vector<vector<int>> & mat, int row, int col) {
		
		if (row == 9) {
			return true;
		}
		
		if (col == 9) {
			return solve(mat, row + 1, 0);
		}
		
		if (mat[row][col] != 0) {
			
			return solve (mat, row, col + 1);
		}
		
		for (int num = 1; num <= 9; num++) {
			
			if (isSafe(row, col, num, mat)) {
				
				mat[row][col] = num;
				
				if (solve(mat, row, col + 1)) {
					return true;
				}
				
				mat[row][col] = 0;
			}
		}
		
		return false;
	}
	
	public:
	
	void solveSudoku(vector<vector<int>> & mat) {
		
		solve(mat, 0, 0);
		
	}
	
};
