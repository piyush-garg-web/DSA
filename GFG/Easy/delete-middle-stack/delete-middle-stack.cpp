class Solution {
	public:
	void deleteMid(stack<int>& s) {
		
		int middle = s.size()/2 + 1;
		
		stack<int> temp; ;
		
		while (middle != 0) {
			temp.push(s.top());
			s.pop();
			middle--;
		}
		
		temp.pop();
		
		while (!temp.empty()) {
			s.push(temp.top());
			temp.pop();
		}
		
	}
};
