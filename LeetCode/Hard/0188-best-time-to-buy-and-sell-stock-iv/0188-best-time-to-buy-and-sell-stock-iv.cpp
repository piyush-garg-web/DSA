class Solution {
private:
    int solve(vector<int>& prices, int n, int k) {
        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int opr = 0; opr < 2 * k; opr++) {
                int profit = 0;

                if (opr % 2 == 0) {
                    int buy = -prices[index] + next[opr + 1];
                    int skip = 0 + next[opr];
                    profit = max(buy, skip);
                } else {
                    int sell = prices[index] + next[opr + 1];
                    int skip = 0 + next[opr];
                    profit = max(sell, skip);
                }

                curr[opr] = profit;
            }
            next = curr;
        }

        return next[0];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solve(prices, n, k);
    }
};