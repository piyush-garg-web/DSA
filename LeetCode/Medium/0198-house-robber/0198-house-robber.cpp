class Solution {
private:
    int solve(vector<int>& nums, int n) {
        int prev1 = nums[0];
        int prev2 = 0;

        for (int i = 1; i < n; i++) {
            int include = nums[i];

            if (i - 2 >= 0) {
                include += prev2;
            }

            int exclude = prev1 + 0;
            int ans = max(include, exclude);
            prev2 = prev1;
            prev1 = ans;
        }

        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, n);
    }
};