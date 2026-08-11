class Solution {
	private:
	void solve (vector<int>& arr, vector<vector<int>> & ans, vector<int>& temp, int target, int index) {
		
		if (index >= arr.size() || target<0) {
			return;
		}
		
		if (target == 0) {
			ans.push_back(temp);
			return;
		}
		
		temp.push_back(arr[index]);
		
		solve (arr, ans, temp, target - arr[index], index);
		
		temp.pop_back();
		
		solve (arr, ans, temp, target, index + 1);
		
	}
	
	public:
	vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
		
		vector<vector<int>> ans;
		vector<int> temp;
		
		solve(arr, ans, temp, target, 0);
		
		return ans;
		
	}
};
