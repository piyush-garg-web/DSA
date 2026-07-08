class Solution {
private:
    int solve(vector<int>& prices, int n) {
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if (buy) {
                    int buyK = -prices[index] + next[0];
                    int skip = 0 + next[1];
                    profit = max(buyK, skip);
                } else {
                    int sell = prices[index] + next[1];
                    int skip = 0 + next[0];
                    profit = max(sell, skip);
                }

                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(prices, n);
    }
};