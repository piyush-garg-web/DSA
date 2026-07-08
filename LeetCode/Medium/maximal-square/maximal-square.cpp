class Solution {
private:
    int solve(int m, int n, vector<vector<char>>& matrix, int& maxi) {
        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int right = curr[j + 1];
                int down = next[j];
                int diagonal = next[j + 1];

                if (matrix[i][j] == '1') {
                    int ans = 1 + min(right, min(down, diagonal));
                    curr[j] = ans;
                    maxi = max(maxi, ans);
                } else {
                    curr[j] = 0;
                }
            }
            next = curr;
        }

        return maxi;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;
        int ans = solve(m, n, matrix, maxi);
        return maxi * maxi;
    }
};