class Solution {
	public:
	vector<int> spirallyTraverse(vector<vector<int>> &mat) {
		
		vector<int> ans;
		int n = mat.size();
		int m = mat[0].size();
		int total = n*m;
		int count = 0;
		
		int sR = 0;
		int eR = n - 1;
		int sC = 0;
		int eC = m - 1;
		
		while (count<total) {
			for (int i = sC; i <= eC && count<total ; i++) {
				ans.push_back(mat[sR][i]);
				count++;
			}
			sR++;
			
			for (int i = sR; i <= eR && count<total ; i++) {
				ans.push_back(mat[i][eC]);
				count++;
			}
			eC--;
			
			for (int i = eC; i >= sC && count<total ; i--) {
				ans.push_back(mat[eR][i]);
				count++;
			}
			eR--;
			
			for (int i = eR; i >= sR && count<total ; i--) {
				ans.push_back(mat[i][sC]);
				count++;
			}
			sC++;
		}
		
		return ans;
		
	}
};