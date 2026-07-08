class Solution {
	private:
	int bSearch (vector<int>& arr, int x, int cond) {
		int low = 0;
		int high = arr.size() - 1;
		int ans = -1;
		
		while (low <= high) {
			int mid = low + (high - low)/2;
			
			if (arr[mid] == x) {
				ans = mid;
				
				if (cond == 1) {
					high = mid - 1;
				}
				
				else {
					low = mid + 1;
				}
			}
			
			else if (arr[mid]<x) {
				low = mid + 1;
			}
			
			else {
				high = mid - 1;
			}
		}
		
		return ans;
	}
	
	public:
	vector<int> find(vector<int>& arr, int x) {
		
		return {bSearch(arr, x, 1), bSearch(arr, x, 0)};
		
	}
};
