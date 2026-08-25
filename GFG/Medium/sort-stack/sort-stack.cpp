class Solution {
	private:
	void insert(stack<int>& st, int x) {
		
		if (st.empty () || x >= st.top()) {
			
			st.push(x);
			return;
		}
		
		int top = st.top();
		st.pop();
		
		insert(st, x);
		
		st.push(top);
	}
	
	public:
	void sortStack(stack<int> &st) {
		
		if (st.empty()) {
			
			return;
		}
		
		int x = st.top();
		st.pop();
		
		sortStack(st);
		
		insert(st, x);
		
	}
};
