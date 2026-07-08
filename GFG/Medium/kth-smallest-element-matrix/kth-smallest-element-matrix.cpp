class Solution {
	private:
	int count (vector<vector<int>> & mat, int target, int n) {
		int result = 0;
		int i = 0;
		int j = n - 1;
		
		while (i<n && j >= 0) {
			if (mat[i][j] <= target) {
				result += j + 1;
				i++;
			}
			
			else {
				j--;
			}
		}
		
		return result;
	}
	
	public:
	int kthSmallest(vector<vector<int>> &mat, int k) {
		
		int n = mat.size();
		int ans = -1;
		int low = mat[0][0];
		int high = mat[n - 1][n - 1];
		
		while (low <= high) {
			int mid = low + (high - low)/2;
			int resultantCount = count(mat, mid, n);
			
			if (resultantCount >= k) {
				ans = mid;
				high = mid - 1;
			}
			
			else {
				low = mid + 1;
			}
			
		}
		
		return ans;
		
	}
};
