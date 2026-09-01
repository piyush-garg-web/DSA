class Solution {
	public:
	int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
		
		int sX = knightPos[0]-1;
		int sY = knightPos[1]-1;
		
		int tX = targetPos[0]-1;
		int tY = targetPos[1]-1;
		
		if (sX == tX && sY == tY) {
			
			return 0;
		}
		
		vector<vector<bool>> visited (n, vector<bool> (n, false));
		queue<pair<int, pair<int, int>> > q;
		
		q.push({0, {sX, sY}});
		visited[sX][sY] = true;
		
		int dX[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
		int dY[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
		
		while (!q.empty()) {
			
			auto top = q.front();
			
			int x = top.second.first;
			int y = top.second.second;
			int moves = top.first;
			
			q.pop();
			
			for (int i = 0; i<8; i++) {
				
				int nX = x + dX[i];
				int nY = y + dY[i];
				
				if (nX >= 0 && nX < n && nY >= 0 && nY < n && !visited[nX][nY]) {
					
					if (nX == tX && nY == tY) {
						
						return moves + 1;
					}
					
					visited[nX][nY] = true;
					q.push({moves + 1, {nX, nY}});
				}
			}
		}
		
	}
};
