class Solution {
private:
    int solve(int n, vector<int>& nums, vector<int>& ans) {
        if (n == 0) {
            return 0;
        }

        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        return solve(n, nums, ans);
    }
};