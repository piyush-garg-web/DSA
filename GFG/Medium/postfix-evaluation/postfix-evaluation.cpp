class Solution {
	public:
	int evaluatePostfix(vector<string>& arr) {
		
		stack <int> st;
		
		for (string s:arr) {
			
			if (s != "+" && s != "-" && s != "*" && s != "/" && s != "^") {
				
				st.push(stoi(s));
			}
			
			else {
				
				int a = st.top();
				st.pop();
				
				int b = st.top();
				st.pop();
				
				int result;
				
				if (s == "+") {
					
					result = b + a;
				}
				
				else if (s == "-") {
					
					result = b - a;
				}
				
				else if (s == "*") {
					
					result = b*a;
				}
				
				else if (s == "/") {
					
					result = floor((double)b/a);
				}
				
				else {
					
					result = pow(b, a);
				}
				
				st.push(result);
			}
		}
		
		return st.top();
	}
};
