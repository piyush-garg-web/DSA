class Solution {
	public:
	int minimumDays(int S, int N, int M) {
		
		if (S>6 && 6*N <7*M) {
			return - 1;
		}
		
		int sundays = S/7;
		int buyingDays = S - sundays;
		
		int reqFood = S*M;
		int totalFood = buyingDays*N;
		
		if (totalFood < reqFood) {
			return - 1;
		}
		
		int ans = 0;
		
		if (reqFood % N == 0) {
			ans = reqFood/N;
		}
		
		else {
			ans = reqFood/N + 1;
		}
		
		return ans;
		
	}
};
