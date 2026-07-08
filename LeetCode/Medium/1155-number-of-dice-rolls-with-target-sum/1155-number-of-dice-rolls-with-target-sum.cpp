class Solution {
private:
    int MOD = 1e9 + 7;
    int solve(int n, int k, int target) {

        vector<int> curr (target+1,0);
        vector<int> next (target+1,0);
        next[target] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = target - 1; j >= 0; j--) {
                int ans = 0;
                for (int dice = 1; dice <= k; dice++) {

                    if (i + 1 <= n && j + dice <= target) {
                        ans = (ans + next[j + dice]) % MOD;
                    }
                }

                curr[j] = ans % MOD;
            }
            next=curr;
        }
        return next[0];
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        return solve(n, k, target);
    }
};