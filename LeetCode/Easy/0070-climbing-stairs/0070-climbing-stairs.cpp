class Solution {
    int solve(int n) {

        vector<int> dp(n + 1, 0);

        int prev1 = 1;
        int prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int oneStep = prev1;
            int twoSteps = prev2;
            int ans = oneStep + twoSteps;
            prev1=prev2;
            prev2=ans;
        }

        return prev2;
    }

public:
    int climbStairs(int n) { return solve(n); }
};