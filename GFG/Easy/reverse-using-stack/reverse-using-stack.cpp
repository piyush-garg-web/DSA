class Solution {
	public:
	string reverse(const string& S) {
		
		stack<char> s;
		
		for (char ch:S) {
			s.push(ch);
		}
		
		string ans = "";
		
		while (!s.empty()) {
			
			ans += s.top();
			s.pop();
		}
		
		return ans;
		
	}
};
