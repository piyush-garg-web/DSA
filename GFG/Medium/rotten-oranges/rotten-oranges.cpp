class Solution {
	public:
	int orangesRot(vector<vector<int>> & mat) {
		
		int n = mat.size();
		int m = mat[0].size();
		
		queue<pair<int, int>> q;
		int fresh = 0;
		
		for (int i = 0 ; i<n; i++) {
			
			for (int j = 0; j<m; j++) {
				
				if (mat[i][j] == 2) {
					
					q.push({i, j});
				}
				
				else if (mat[i][j] == 1) {
					
					fresh++;
				}
			}
		}
		
		int time = 0;
		
		int x[] = {-1, 0, 1, 0};
		int y[] = {0, 1, 0, -1};
		
		while (!q.empty() && fresh>0) {
			
			int size = q.size();
			
			while (size != 0) {
				
				auto it = q.front();
				q.pop();
				
				for (int i = 0; i<4; i++) {
					
					int newX = it.first + x[i];
					int newY = it.second + y[i];
					
					if (newX >= 0 && newX<n && newY >= 0 && newY<m && mat[newX][newY] == 1) {
						
						mat[newX][newY] = 2;
						fresh--;
						
						q.push({newX, newY});
					}
				}
				
				size--;
				
			}
			
			time++;
		}
		
		if (fresh == 0) {
			
			return time;
		}
		
		else {
			
			return - 1;
		}
	}
};
