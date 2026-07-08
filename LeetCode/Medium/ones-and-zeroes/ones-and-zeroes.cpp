class Solution {
private:
    int solve(int size, int m, int n, vector<pair<int, int>>& count) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < size; i++) {
            int zero = count[i].first;
            int one = count[i].second;

            for (int j = m; j >= zero; j--) {
                for (int k = n; k >= one; k--) {
                    int include = 1 + dp[j - zero][k - one];
                    int exclude = dp[j][k];
                    dp[j][k] = max(include, exclude);
                }
            }
        }

        return dp[m][n];
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<pair<int, int>> count;

        for (string str : strs) {
            int zero = 0;
            int one = 0;

            for (char ch : str) {
                if (ch == '0') {
                    zero++;
                } else {
                    one++;
                }
            }

            count.push_back({zero, one});
        }

        return solve(size, m, n, count);
    }
};