class Solution {
private:
    int solve(int sum, vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return (int)dp[target];
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        return solve(0, nums, target);
    }
};