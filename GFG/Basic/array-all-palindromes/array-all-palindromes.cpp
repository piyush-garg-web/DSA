class Solution {
	private:
	bool reverse (int num) {
		int ori = num;
		int rev = 0;
		
		while (num>0) {
			int digit = num%10;
			rev = rev*10 + digit;
			num = num/10;
			
		}
		
		return ori == rev;
	}
	public:
	bool isPalinArray(vector<int> &arr) {
		for (int i = 0; i<arr.size(); i++) {
			if (!reverse(arr[i])) {
				return false;
			}
		}
		
		return true;
	}
};
