class Solution {
	public:
	bool checkRedundancy(string &s) {
		
		stack<char> st;
		
		for (int i = 0; i<s.size(); i++) {
			
			if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
				
				st.push(s[i]);
			}
			
			else {
				
				if (s[i] == ')') {
					
					bool check = true;
					while (st.top() != '(') {
						
						char curr = st.top();
						st.pop();
						
						if (curr == '+' || curr == '-' || curr == '*' || curr == '/') {
							
							check = false;
							
						}
					}
					
					if (check) {
						
						return true;
					}
					
					st.pop();
				}
			}
		}
		
		return false;
		
	}
};
