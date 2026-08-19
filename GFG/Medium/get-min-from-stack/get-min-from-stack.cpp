class SpecialStack {
	
	stack<int> st;
	stack<int> mini;
	
	public:
	SpecialStack() {
		
	}
	
	void push(int x) {
		
		st.push(x);
		
		if (mini.empty()) {
			mini.push(x);
		}
		
		else {
			mini.push(min(x, mini.top()));
		}
	}
	
	void pop() {
		
		if (!st.empty()) {
			
			st.pop();
			mini.pop();
		}
		
	}
	
	int peek() {
		
		if (st.empty()) {
			return - 1;
		}
		
		return st.top();
	}
	
	bool isEmpty() {
		
		if (st.empty()) {
			return true;
		}
		
		return false;
	}
	
	int getMin() {
		
		if (st.empty()) {
			return - 1;
		}
		
		return mini.top();
	}
};
