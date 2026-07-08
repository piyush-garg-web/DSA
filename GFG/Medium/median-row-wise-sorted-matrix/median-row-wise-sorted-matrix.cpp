class Solution {
	private:
	int count (vector<int>& row, int m, int target) {
		int ans = 0;
		
		int low = 0;
		int high = m - 1;
		
		while (low <= high) {
			int mid = low + (high - low)/2;
			if (row[mid] <= target) {
				ans += mid - low + 1;
				low = mid + 1;
			}
			
			else {
				high = mid - 1;
			}
		}
		
		return ans;
	}
	
	public:
	int median(vector<vector<int>> &mat) {
		
		int n = mat.size();
		int m = mat[0].size();
		
		int low = INT_MAX;
		int high = INT_MIN;
		
		for (int i = 0; i<n; i++) {
			low = min(low, mat[i][0]);
			high = max(high, mat[i][m - 1]);
		}
		
		int requiredCount = (n*m)/2;
		
		while (low<high) {
			int mid = low + (high - low)/2;
			int actualCount = 0;
			
			for (int i = 0; i<n; i++) {
				actualCount += count(mat[i], m, mid);
			}
			
			if (actualCount <= requiredCount) {
				low = mid + 1;
			}
			
			else {
				high = mid;
			}
			
		}
		
		return high;
		
	}
};
