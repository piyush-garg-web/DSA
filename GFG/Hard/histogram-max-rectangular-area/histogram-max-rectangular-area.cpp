class Solution {
	private:
	void greater (vector<int>& arr, vector<int>& nextSmaller) {
		
		stack<int> st;
		
		for (int i = arr.size() - 1; i >= 0; i--) {
			
			while (!st.empty() && arr[st.top()] >= arr[i]) {
				st.pop();
			}
			
			if (st.empty()) {
				
				nextSmaller[i] = arr.size();
				
			}
			
			else {
				
				nextSmaller[i] = st.top();
			}
			
			st.push(i);
		}
	}
	
	void smaller (vector<int>& arr, vector<int>& prevSmaller) {
		
		stack<int> st;
		
		for (int i = 0; i<arr.size(); i++) {
			
			while (!st.empty() && arr[st.top()] >= arr[i]) {
				st.pop();
			}
			
			if (st.empty()) {
				
				prevSmaller[i] = -1;
				
			}
			
			else {
				
				prevSmaller[i] = st.top();
			}
			
			st.push(i);
		}
	}
	
	public:
	int getMaxArea(vector<int> &arr) {
		
		int n = arr.size();
		vector<int> nextSmaller (n);
		vector<int> prevSmaller (n);
		
		greater(arr, nextSmaller);
		smaller(arr, prevSmaller);
		
		int maxi = INT_MIN;
		for (int i = 0; i<arr.size(); i++) {
			
			int width = nextSmaller[i]-prevSmaller[i]-1;
			int height = arr[i];
			
			int area = width*height;
			maxi = max(maxi, area);
		}
		
		return maxi;
	}
};
