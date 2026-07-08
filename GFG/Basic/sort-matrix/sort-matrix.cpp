class Solution {
	public:
	vector<vector<int>> sortedMatrix(vector<vector<int>> mat) {
		
		vector<int> temp;
		int n = mat.size();
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				temp.push_back(mat[i][j]);
			}
		}
		
		sort(temp.begin(), temp.end());
		int k = 0;
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) {
				mat[i][j] = temp[k];
				k++;
			}
		}
		
		return mat;
	}
};
