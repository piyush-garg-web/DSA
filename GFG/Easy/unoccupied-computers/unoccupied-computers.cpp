class Solution {
	public:
	int solve(int n, string s) {
		
		vector<int> state (26, 0) ;
		int occupied = 0;
		int rejected = 0;
		
		for (int i = 0; i<s.size(); i++) {
			
			int index = s[i]-'A';
			
			if (state[index] == 0) {
				
				if (occupied<n) {
					state[index] = 1;
					occupied++;
				}
				
				else {
					state[index] = 2;
					rejected++;
				}
			}
			
			else {
				if (state[index] == 1) {
					occupied--;
				}
				
				state[index] = 0;
			}
			
		}
		
		return rejected;
		
	}
};
