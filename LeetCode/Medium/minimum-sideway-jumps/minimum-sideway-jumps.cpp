class Solution {
private:
    int solve(vector<int>& obstacles, int n) {
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= 3; j++) {
                if (obstacles[i + 1] != j) {
                    curr[j] = next[j];
                } else {
                    int ans = INT_MAX;

                    for (int k = 1; k <= 3; k++) {
                        if (k != j && obstacles[i] != k) {
                            ans = min(ans, 1 + next[k]);
                        }
                    }

                    curr[j] = ans;
                }
            }
            next = curr;
        }

        return min(next[2], min(1 + next[1], 1 + next[3]));
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        return solve(obstacles, n);
    }
};