class Solution {
	public:
	int rowWithMax1s(vector<vector<int>> &arr) {
		
		int n = arr.size();
		int m = arr[0].size();
		
		int r = 0;
		int c = m -1;
		int ans = -1;
		
		while (r<n && c >= 0) {
			if (arr[r][c] == 1) {
				ans = r;
				c--;
			}
			else {
				r++;
			}
		}
		
		return ans;
		
	}
};
