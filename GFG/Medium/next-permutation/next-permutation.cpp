class Solution {
	public:
	void nextPermutation(vector<int>& arr) {
		
		int n = arr.size();
		int index = -1;
		
		for (int i = n - 2; i >= 0; i--) {
			if (arr[i]<arr[i + 1]) {
				index = i;
				break;
			}
		}
		
		if (index == -1) {
			int i = 0;
			int j = n - 1;
			
			while (i<j) {
				swap(arr[i], arr[j]);
				i++;
				j--;
			}
			
			return;
		}
		
		for (int i = n - 1; i>index; i--) {
			if (arr[i]>arr[index]) {
				swap(arr[i], arr[index]);
				break;
			}
		}
		
		int i = index + 1;
		int j = n - 1;
		
		while (i<j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		
	}
	
};
