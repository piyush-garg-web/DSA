class Solution {
	public:
	bool validateOp(vector<int>& a, vector<int>& b) {
		
		stack<int> st;
		int j = 0;
		
		for (int x : a) {
			
			st.push(x);
			
			while (!st.empty() && j<b.size() && b[j] == st.top()) {
				
				st.pop();
				j++;
			}
		}
		
		return j == b.size();
		
	}
};
