class Solution {
private:
    bool solve(vector<int>& nums, int n, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        return solve(nums, n, sum / 2);
    }
};