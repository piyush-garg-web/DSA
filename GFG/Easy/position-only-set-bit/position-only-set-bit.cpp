class Solution {
	public:
	int findPosition(int n) {
		
		int count = 0;
		int pos = 0;
		int currPos = 0;
		
		while (n>0) {
			
			currPos += 1;
			
			if (n&1) {
				
				count++;
				pos = currPos;
			}
			
			n = n>> 1;
		}
		
		if (count == 1) {
			
			return pos;
		}
		
		return - 1;
		
	}
};
